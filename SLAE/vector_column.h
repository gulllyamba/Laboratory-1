#ifndef VECTOR_COLUMN_H
#define VECTOR_COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include "../src/types/TypesInfo.h"
#include "../src/Error/error.h"
#include "../src/types/INT/INT.h"
#include "../src/types/DOUBLE/DOUBLE.h"
#include <string.h>
#include <stdbool.h>

typedef struct vector_column {
    int row;
    void* data;
    const TypeInfo_t* type;
} vector_column_t;

vector_column_t* create_vector_column(const int row, const DataType_t type);

void free_vector(vector_column_t* vector);

char* toString_vector(const vector_column_t* vector);

void* get_element_vector(const vector_column_t* vector, const int row);

void set_element_vector(vector_column_t* vector, const int row, void* value);

void init_zeros_vector(vector_column_t** vector);

#endif // VECTOR_COLUMN_H