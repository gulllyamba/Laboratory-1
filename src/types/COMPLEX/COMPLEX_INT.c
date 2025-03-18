#include "COMPLEX_INT.h"

void init_zero_complex_int(void* value_result) {
    ((Complex_int_t*)value_result)->Re = 0;
    ((Complex_int_t*)value_result)->Im = 0;
}

Complex_int_t* create_complex_int(void* Re, void* Im) {
    Complex_int_t* complex = (Complex_int_t*)malloc(sizeof(Complex_int_t));
    if (complex == NULL) {
        return NULL;
    }
    complex->Re = *(int*)Re;
    complex->Im = *(int*)Im;
    return complex;
}

void fill_complex_int(Complex_int_t* complex, void* Re, void* Im) {
    complex->Re = *(int*)Re;
    complex->Im = *(int*)Im;
}

void sum_complex_int(void* value_a, void* value_b, void* value_result) {
    Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
    Complex_int_t* cvalue_b = (Complex_int_t*)value_b;
    Complex_int_t* cvalue_result = (Complex_int_t*)value_result;
    cvalue_result->Re = cvalue_a->Re + cvalue_b->Re;
    cvalue_result->Im = cvalue_a->Im + cvalue_b->Im;
    value_result = cvalue_result;
}

void multiply_complex_int(void* value_a, void* value_b, void* value_result) {
    Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
    Complex_int_t* cvalue_b = (Complex_int_t*)value_b;
    Complex_int_t* cvalue_result = (Complex_int_t*)value_result;
    cvalue_result->Re = cvalue_a->Re * cvalue_b->Re - cvalue_a->Im * cvalue_b->Im;
    cvalue_result->Im = cvalue_a->Re * cvalue_b->Im + cvalue_a->Im * cvalue_b->Re;
    value_result = cvalue_result;
}

void multiply_scalar_complex_int(void* value_a, void* scalar, void* value_result) {
    Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
    Complex_int_t* cvalue_result = (Complex_int_t*)value_result;
    cvalue_result->Re = cvalue_a->Re * *(int*)scalar;
    cvalue_result->Im = cvalue_a->Im * *(int*)scalar;
    value_result = cvalue_result;
}

// void print_complex_int(void* value_a) {
//     Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
//     printf("(%d + %di) ", cvalue_a->Re, cvalue_a->Im);
// }

void div_complex_int(void* value_a, void* value_b, void* value_result) {
    Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
    Complex_int_t* cvalue_b = (Complex_int_t*)value_b;
    Complex_int_t* cvalue_result = (Complex_int_t*)value_result;
    cvalue_result->Re = (cvalue_a->Re * cvalue_b->Re + cvalue_a->Im * cvalue_b->Im) / (cvalue_b->Re * cvalue_b->Re + cvalue_b->Im * cvalue_b->Im);
    cvalue_result->Im = (cvalue_a->Im * cvalue_b->Re - cvalue_a->Re * cvalue_b->Im) / (cvalue_b->Re * cvalue_b->Re + cvalue_b->Im * cvalue_b->Im);
    value_result = cvalue_result;
}

void diff_complex_int(void* value_a, void* value_b, void* value_result) {
    Complex_int_t* cvalue_a = (Complex_int_t*)value_a;
    Complex_int_t* cvalue_b = (Complex_int_t*)value_b;
    Complex_int_t* cvalue_result = (Complex_int_t*)value_result;
    cvalue_result->Re = cvalue_a->Re - cvalue_b->Re;
    cvalue_result->Im = cvalue_a->Im - cvalue_b->Im;
    value_result = cvalue_result;
}

void toString_complex_int(void* value, int* cnt, char** buff, size_t* buff_size) {
    Complex_int_t* cvalue = (Complex_int_t*)value;
    *cnt += snprintf(*buff + *cnt, *buff_size - *cnt, "(%d+%di)", cvalue->Re, cvalue->Im);
}

void free_complex_int(Complex_int_t* complex) {
    free(complex);
}

TypeInfo_t ComplexIntType = {
    .size = sizeof(Complex_int_t),
    .size_for_linear_combination = sizeof(int),
    .init_zero = init_zero_complex_int,
    .div = div_complex_int,
    .diff = diff_complex_int,
    .toString = toString_complex_int,
    .sum = sum_complex_int,
    .multiply = multiply_complex_int,
    .multiply_scalar = multiply_scalar_complex_int,
    // .print = print_complex_int,
    .type = COMPLEX_INT
};