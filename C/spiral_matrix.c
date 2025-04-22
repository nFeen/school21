#include <stdio.h>
#include <stdlib.h>

void output_matrix(int **matrix, int n);
void allocate_matrix(int ***matrix, int n);
void fill_matrix(int **matrix, int n);
void free_matrix(int **matrix, int n);
void fill_array(int *array, int n);
void spiral_matrix(int **matrix, int n, int *array);

int main() {
    int **matrix, n;
    scanf("%d", &n);
    int *array = malloc(n * n * sizeof(int));
    fill_array(array, n);

    allocate_matrix(&matrix, n);
    fill_matrix(matrix, n);
    spiral_matrix(matrix, n, array);

    free(array);

    output_matrix(matrix, n);

    free_matrix(matrix, n);
}

void allocate_matrix(int ***matrix, int n) {
    *matrix = malloc(sizeof(int *) * (n + 2));
    for (int i = 0; i < n + 2; i++) {
        (*matrix)[i] = malloc(sizeof(int) * (n + 2));
    }
}

void fill_matrix(int **matrix, int n) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void output_matrix(int **matrix, int n) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n + 2; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_array(int *array, int n) {
    for (int i = 1; i < n * n + 1; i++) {
        array[i - 1] = i;
    }
}

void spiral_matrix(int **matrix, int n, int *array) {
    int x = 1, y = 1, vector_x = 1, vector_y = 0, count = 0;
    while (count < n * n) {
        if (matrix[y + vector_y][x + vector_x] != 0) {
            if (vector_x == 1 && vector_y == 0) {
                vector_x = 0;
                vector_y = 1;
            } else if (vector_x == 0 && vector_y == 1) {
                vector_x = -1;
                vector_y = 0;
            } else if (vector_x == -1 && vector_y == 0) {
                vector_x = 0;
                vector_y = -1;
            } else if (vector_x == 0 && vector_y == -1) {
                vector_x = 1;
                vector_y = 0;
            }
        }

        matrix[y][x] = array[count];
        y = y + vector_y;
        x = x + vector_x;
        count++;
    }
}