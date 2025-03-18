#ifndef TYPES_COMPLEX_COMPLEX_DOUBLE_H
#define TYPES_COMPLEX_COMPLEX_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include "../TypesInfo.h"

extern TypeInfo_t ComplexDoubleType;

typedef struct Complex_double {
    double Re;
    double Im;
} Complex_double_t;

void init_zero_complex_double(void* value_result);

Complex_double_t* create_complex_double(void* Re, void* Im);

void fill_complex_double(Complex_double_t* complex, void* Re, void* Im);

void sum_complex_double(void* value_a, void* value_b, void* value_result);

void multiply_complex_double(void* value_a, void* value_b, void* value_result);

void multiply_scalar_complex_double(void* value_a, void* scalar, void* value_result);

void div_complex_double(void* value_a, void* value_b, void* value_result);

void diff_complex_double(void* value_a, void* value_b, void* value_result);

// void print_complex_double(void* value_a);

void toString_complex_double(void* value, int* cnt, char** buff, size_t* buff_size);

void free_complex_double(Complex_double_t* complex);

#endif //TYPES_COMPLEX_COMPLEX_DOUBLE_H