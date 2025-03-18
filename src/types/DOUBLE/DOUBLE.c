#include "DOUBLE.h"

void init_zero_double(void* value_result) {
    *(double*)value_result = 0.0;
}

void sum_double(void* value_a, void* value_b, void* value_result) {
    *(double*)value_result = *(double*)value_a + *(double*)value_b;
}

void multiply_double(void* value_a, void* value_b, void* value_result) {
    *(double*)value_result = *(double*)value_a * *(double*)value_b;
}

void multiply_scalar_double(void* value_a, void* scalar, void* value_result) {
    *(double*)value_result = *(double*)value_a * *(double*)scalar;
}

void div_double(void* value_a, void* value_b, void* value_result) {
    *(double*)value_result = *(double*)value_a / *(double*)value_b;
}

void diff_double(void* value_a, void* value_b, void* value_result) {
    *(double*)value_result = *(double*)value_a - *(double*)value_b;
}

// void print_double(void* value_a) {
//     printf("%lf ", *(double*)value_a);
// }

void toString_double(void* value, int* cnt, char** buff, size_t* buff_size) {
    *cnt += snprintf(*buff + *cnt, *buff_size - *cnt, "%.3lf", *(double*)value);
}

TypeInfo_t DoubleType = {
    .size = sizeof(double),
    .size_for_linear_combination = sizeof(double),
    .init_zero = init_zero_double,
    .div = div_double,
    .diff = diff_double,
    .toString = toString_double,
    .sum = sum_double,
    .multiply = multiply_double,
    .multiply_scalar = multiply_scalar_double,
    // .print = print_double,
    .type = DOUBLE
};