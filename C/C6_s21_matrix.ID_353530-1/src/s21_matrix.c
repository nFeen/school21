#include "s21_helpers.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = malloc(columns * sizeof(double));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0;
    }
  }

  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;
  if (correct_matrix(A) && correct_matrix(B) && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows && return_value; i++) {
      for (int j = 0; j < A->columns && return_value; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7)
          return_value = FAILURE;
      }
    }
  } else {
    return_value = FAILURE;
  }

  return return_value;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(correct_matrix(A) && correct_matrix(B))) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return MATH_FAIL;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(correct_matrix(A) && correct_matrix(B))) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return MATH_FAIL;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!correct_matrix(A)) return INCORRECT_MATRIX;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(correct_matrix(A) && correct_matrix(B))) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return MATH_FAIL;

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A)) return INCORRECT_MATRIX;

  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (!correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return MATH_FAIL;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = recursive_determinant(A);
  }

  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return MATH_FAIL;

  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t smaller_matrix = {0};
        double minor;
        create_smaller_matrix(A, i, j, &smaller_matrix);
        s21_determinant(&smaller_matrix, &minor);
        result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor;
        s21_remove_matrix(&smaller_matrix);
      }
    }
  }

  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return MATH_FAIL;

  int return_value = OK;
  double determinant;
  s21_determinant(A, &determinant);
  if (determinant != 0) {
    if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / determinant;
    } else {
      matrix_t complements, transposed_complements;
      s21_calc_complements(A, &complements);
      s21_transpose(&complements, &transposed_complements);
      s21_mult_number(&transposed_complements, 1 / determinant, result);
      s21_remove_matrix(&complements);
      s21_remove_matrix(&transposed_complements);
    }
  } else {
    return_value = MATH_FAIL;
  }

  return return_value;
}