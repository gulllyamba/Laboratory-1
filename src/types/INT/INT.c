#include "INT.h"

void init_zero_int(void* value_result) {
    *(int*)value_result = 0;
}

void sum_int(void* value_a, void* value_b, void* value_result) {
    *(int*)value_result = *(int*)value_a + *(int*)value_b;
}

void multiply_int(void* value_a, void* value_b, void* value_result) {
    *(int*)value_result = *(int*)value_a * *(int*)value_b;
}

void multiply_scalar_int(void* value_a, void* scalar, void* value_result) {
    *(int*)value_result = *(int*)value_a * *(int*)scalar;
}

void div_int(void* value_a, void* value_b, void* value_result) {
    *(int*)value_result = *(int*)value_a / *(int*)value_b;
}

void diff_int(void* value_a, void* value_b, void* value_result) {
    *(int*)value_result = *(int*)value_a - *(int*)value_b;
}

// void print_int(void* value_a) {
//     printf("%d ", *(int*)value_a);
// }

void toString_int(void* value, int* cnt, char** buff, size_t* buff_size) {
    *cnt += snprintf(*buff + *cnt, *buff_size - *cnt, "%d", *(int*)value);
}

TypeInfo_t IntType = {
    .size = sizeof(int),
    .size_for_linear_combination = sizeof(int),
    .init_zero = init_zero_int,
    // .print = print_int,
    .div = div_int,
    .diff = diff_int,
    .toString = toString_int,
    .sum = sum_int,
    .multiply = multiply_int,
    .multiply_scalar = multiply_scalar_int,
    .type = INT
};