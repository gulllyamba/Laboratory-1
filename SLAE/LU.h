#ifndef LU_H
#define LU_H

#include "../src/square_matrix.h"
#include "../src/Error/error.h"
#include "vector_column.h"
#include <math.h>

int solutions(SquareMatrix_t* matrix);

SquareMatrix_t* inverse_matrix(SquareMatrix_t* matrix);

vector_column_t* count_vector_column(SquareMatrix_t* inverse, vector_column_t* b);

void LU(SquareMatrix_t* A, SquareMatrix_t** L, SquareMatrix_t** U);

void init_matrix(SquareMatrix_t** A, int size, char* buff);

void print_matrix(SquareMatrix_t* matrix);

#endif // LU_H