#ifndef S21_HELPERS_H
#define S21_HELPERS_H

#include "s21_matrix.h"

int correct_matrix(matrix_t *A);
double recursive_determinant(matrix_t *A);
void create_smaller_matrix(matrix_t *matrix, int row, int column,
                           matrix_t *new_matrix);
void from_array(double *arr, matrix_t *matrix);
void full_one(matrix_t *matrix);

#endif