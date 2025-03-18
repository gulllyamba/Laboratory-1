#ifndef TYPES_INT_INT_H
#define TYPES_INT_INT_H

#include <stdio.h>
#include "../TypesInfo.h"

extern TypeInfo_t IntType;

typedef struct Int {
    int value;
} Int_t;

void init_zero_int(void* value_result);

void sum_int(void* value_a, void* value_b, void* value_result);

void multiply_int(void* value_a, void* value_b, void* value_result);

void multiply_scalar_int(void* value_a, void* scalar, void* value_result);

void div_int(void* value_a, void* value_b, void* value_result);

void diff_int(void* value_a, void* value_b, void* value_result);

// void print_int(void* value_a);

void toString_int(void* value, int* cnt, char** buff, size_t* buff_size);

#endif //TYPES_INT_INT_H