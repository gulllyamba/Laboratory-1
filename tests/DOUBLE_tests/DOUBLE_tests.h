#ifndef TESTS_DOUBLE_TESTS_DOUBLE_TESTS_H
#define TESTS_DOUBLE_TESTS_DOUBLE_TESTS_H

#include "../../src/square_matrix.h"
#include "../../src/Error/error.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_matrix_double_tests(SquareMatrix_t** A, int size, char* buff);

void sum_matrix_double_tests(SquareMatrix_t* A, SquareMatrix_t* B, SquareMatrix_t** result, char* buff);

void multiply_matrix_double_tests(SquareMatrix_t* A, SquareMatrix_t* B, SquareMatrix_t** result, char* buff);

void multiply_scalar_matrix_double_tests(SquareMatrix_t* A, SquareMatrix_t** result, char* buff);

void linear_combination_matrix_double_tests(SquareMatrix_t* A, SquareMatrix_t** result, char* buff);

#endif // TESTS_DOUBLE_TESTS_DOUBLE_TESTS_H