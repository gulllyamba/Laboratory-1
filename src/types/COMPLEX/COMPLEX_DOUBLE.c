#include "COMPLEX_DOUBLE.h"

void init_zero_complex_double(void* value_result) {
    ((Complex_double_t*)value_result)->Re = 0.0;
    ((Complex_double_t*)value_result)->Im = 0.0;
}

Complex_double_t* create_complex_double(void* Re, void* Im) {
    Complex_double_t* complex = (Complex_double_t*)malloc(sizeof(Complex_double_t));
    if (complex == NULL) {
        return NULL;
    }
    complex->Re = *(double*)Re;
    complex->Im = *(double*)Im;
    return complex;
}

void fill_complex_double(Complex_double_t* complex, void* Re, void* Im) {
    complex->Re = *(double*)Re;
    complex->Im = *(double*)Im;
}

void sum_complex_double(void* value_a, void* value_b, void* value_result) {
    Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
    Complex_double_t* cvalue_b = (Complex_double_t*)value_b;
    Complex_double_t* cvalue_result = (Complex_double_t*)value_result;
    cvalue_result->Re = cvalue_a->Re + cvalue_b->Re;
    cvalue_result->Im = cvalue_a->Im + cvalue_b->Im;
    value_result = cvalue_result;
}

void multiply_complex_double(void* value_a, void* value_b, void* value_result) {
    Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
    Complex_double_t* cvalue_b = (Complex_double_t*)value_b;
    Complex_double_t* cvalue_result = (Complex_double_t*)value_result;
    cvalue_result->Re = cvalue_a->Re * cvalue_b->Re - cvalue_a->Im * cvalue_b->Im;
    cvalue_result->Im = cvalue_a->Re * cvalue_b->Im + cvalue_a->Im * cvalue_b->Re;
    value_result = cvalue_result;
}

void multiply_scalar_complex_double(void* value_a, void* scalar, void* value_result) {
    Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
    Complex_double_t* cvalue_result = (Complex_double_t*)value_result;
    cvalue_result->Re = cvalue_a->Re * *(double*)scalar;
    cvalue_result->Im = cvalue_a->Im * *(double*)scalar;
    value_result = cvalue_result;
}

void div_complex_double(void* value_a, void* value_b, void* value_result) {
    Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
    Complex_double_t* cvalue_b = (Complex_double_t*)value_b;
    Complex_double_t* cvalue_result = (Complex_double_t*)value_result;
    cvalue_result->Re = (cvalue_a->Re * cvalue_b->Re + cvalue_a->Im * cvalue_b->Im) / (cvalue_b->Re * cvalue_b->Re + cvalue_b->Im * cvalue_b->Im);
    cvalue_result->Im = (cvalue_a->Im * cvalue_b->Re - cvalue_a->Re * cvalue_b->Im) / (cvalue_b->Re * cvalue_b->Re + cvalue_b->Im * cvalue_b->Im);
    value_result = cvalue_result;
}

void diff_complex_double(void* value_a, void* value_b, void* value_result) {
    Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
    Complex_double_t* cvalue_b = (Complex_double_t*)value_b;
    Complex_double_t* cvalue_result = (Complex_double_t*)value_result;
    cvalue_result->Re = cvalue_a->Re - cvalue_b->Re;
    cvalue_result->Im = cvalue_a->Im - cvalue_b->Im;
    value_result = cvalue_result;
}

// void print_complex_double(void* value_a) {
//     Complex_double_t* cvalue_a = (Complex_double_t*)value_a;
//     printf("(%lf + %lfi) ", cvalue_a->Re, cvalue_a->Im);
// }

void toString_complex_double(void* value, int* cnt, char** buff, size_t* buff_size) {
    Complex_double_t* cvalue = (Complex_double_t*)value;
    *cnt += snprintf(*buff + *cnt, *buff_size - *cnt, "(%.3lf+%.3lfi)", cvalue->Re, cvalue->Im);
}

void free_complex_double(Complex_double_t* complex) {
    free(complex);
}

TypeInfo_t ComplexDoubleType = {
    .size = sizeof(Complex_double_t),
    .size_for_linear_combination = sizeof(double),
    .init_zero = init_zero_complex_double,
    .div = div_complex_double,
    .diff = diff_complex_double,
    .toString = toString_complex_double,
    .sum = sum_complex_double,
    .multiply = multiply_complex_double,
    .multiply_scalar = multiply_scalar_complex_double,
    // .print = print_complex_double,
    .type = COMPLEX_DOUBLE
};