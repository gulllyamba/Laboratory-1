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