#ifndef TYPES_DOUBLE_DOUBLE_H
#define TYPES_DOUBLE_DOUBLE_H

#include <stdio.h>
#include "../TypesInfo.h"

extern TypeInfo_t DoubleType;

typedef struct Double {
    double value;
} Double_t;

void init_zero_double(void* value_result);

void sum_double(void* value_a, void* value_b, void* value_result);

void multiply_double(void* value_a, void* value_b, void* value_result);

void multiply_scalar_double(void* value_a, void* scalar, void* value_result);

void div_double(void* value_a, void* value_b, void* value_result);

void diff_double(void* value_a, void* value_b, void* value_result);

// void print_double(void* value_a);

void toString_double(void* value, int* cnt, char** buff, size_t* buff_size);

#endif //TYPES_DOUBLE_DOUBLE_H