#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types/TypesInfo.h"
#include "Error/error.h"
#include "types/INT/INT.h"
#include "types/DOUBLE/DOUBLE.h"
#include "types/COMPLEX/COMPLEX_INT.h"
#include "types/COMPLEX/COMPLEX_DOUBLE.h"

#define SQUARE_MATRIX(matrix_name, size, type) SquareMatrix_t* matrix_name = create_matrix(size, type)
#define SUMM_MATRICES(matrix_name, matrix_a, matrix_b) SquareMatrix_t* matrix_name = sum_matrix(matrix_a, matrix_b)
#define MULTIPLY_MATRICES(matrix_name, matrix_a, matrix_b) SquareMatrix_t* matrix_name = multiply_matrix(matrix_a, matrix_b)
#define MULTIPLY_SCALAR_MATRICES(matrix_name, matrix_a, scalar) SquareMatrix_t* matrix_name = multiply_matrix_scalar(matrix_a, scalar)
#define LINEAR_COMB(matrix_name, matrix_a, row, coef) SquareMatrix_t* matrix_name = linear_comb(matrix_a, row, coef)

#define COMPLEX_INT(value_name, Re, Im) Complex_int_t* value_name = create_complex_int(Re, Im)
#define COMPLEX_DOUBLE(value_name, Re, Im) Complex_double_t* value_name = create_complex_double(Re, Im)

#define TO_STRING(string, matrix_name) char* string = toString_matrix(matrix_name);

typedef struct SquareMatrix {
    int size;
    void* data;
    const TypeInfo_t* type;
} SquareMatrix_t;

SquareMatrix_t* create_matrix (const int size, const DataType_t type);

void free_matrix(SquareMatrix_t* matrix);

// void print_matrix(const SquareMatrix_t* matrix);

char* toString_matrix(const SquareMatrix_t* matrix);

void* get_element(const SquareMatrix_t* matrix, const int row, const int col);

void set_element(SquareMatrix_t* matrix, const int row, const int col, void* value);

void init_zeros_matrix(SquareMatrix_t** matrix);

SquareMatrix_t* sum_matrix(const SquareMatrix_t* A, const SquareMatrix_t* B);

SquareMatrix_t* multiply_matrix(const SquareMatrix_t* A, const SquareMatrix_t* B);

SquareMatrix_t* transposition(const SquareMatrix_t* matrix);

SquareMatrix_t* multiply_matrix_scalar(const SquareMatrix_t* matrix, void* scalar);

SquareMatrix_t* linear_comb(const SquareMatrix_t* matrix, const int row, void* alhpas);

#endif // SQUARE_MATRIX_H