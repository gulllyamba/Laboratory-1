#ifndef TYPES_COMPLEX_COMPLEX_INT_H
#define TYPES_COMPLEX_COMPLEX_INT_H

#include <stdio.h>
#include <stdlib.h>
#include "../TypesInfo.h"

extern TypeInfo_t ComplexIntType;

typedef struct Complex_int {
    int Re;
    int Im;
} Complex_int_t;

void init_zero_complex_int(void* value_result);

Complex_int_t* create_complex_int(void* Re, void* Im);

void fill_complex_int(Complex_int_t* complex, void* Re, void* Im);

void sum_complex_int(void* value_a, void* value_b, void* value_result);

void multiply_complex_int(void* value_a, void* value_b, void* value_result);

void multiply_scalar_complex_int(void* value_a, void* scalar, void* value_result);

void div_complex_int(void* value_a, void* value_b, void* value_result);

void diff_complex_int(void* value_a, void* value_b, void* value_result);

// void print_complex_int(void* value_a);

void toString_complex_int(void* value, int* cnt, char** buff, size_t* buff_size);

void free_complex_int(Complex_int_t* complex);

#endif //TYPES_COMPLEX_COMPLEX_INT_H