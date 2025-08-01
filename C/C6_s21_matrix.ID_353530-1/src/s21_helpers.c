#include "s21_helpers.h"

int correct_matrix(matrix_t *A) {
  return !(!A || A->columns <= 0 || A->rows <= 0 || A->matrix == NULL);
}

double recursive_determinant(matrix_t *A) {
  double result = 0;
  int sign = 1;
  if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t smaller_matrix = {0};
      create_smaller_matrix(A, 0, i, &smaller_matrix);
      result += A->matrix[0][i] * recursive_determinant(&smaller_matrix) * sign;
      sign = -sign;
      s21_remove_matrix(&smaller_matrix);
    }
  }

  return result;
}

void create_smaller_matrix(matrix_t *matrix, int row, int column,
                           matrix_t *new_matrix) {
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, new_matrix);
  int row_now = 0, column_now = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != row && j != column) {
        new_matrix->matrix[row_now][column_now] = matrix->matrix[i][j];
        column_now++;
        if (column_now == new_matrix->columns) {
          row_now++;
          column_now = 0;
        }
      }
    }
  }
}

void from_array(double *arr, matrix_t *matrix) {
  int score = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = arr[score++];
    }
  }
}

void full_one(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = 1;
    }
  }
}