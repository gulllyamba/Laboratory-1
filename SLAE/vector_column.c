#include "vector_column.h"

void init_zeros_vector(vector_column_t** vector);

vector_column_t* create_vector_column(const int row, const DataType_t type) {
    if (row < 1) {
        char* path = "vector_column.c: In function create_vector_column()";
        error_t Error = ERROR_INVALID_MATRIX_SIZE;
        log_error(Error, path);
        return NULL;
    }
    vector_column_t* result_vector = (vector_column_t*)calloc(1, sizeof(vector_column_t));
    if (result_vector == NULL)  {
        char* path = "vector_column.c: In function create_vector_column()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    result_vector->row = row;
    switch (type)
    {
        case INT:
            result_vector->type = &IntType;
            break;
        case DOUBLE:
            result_vector->type = &DoubleType;
            break;
        default:
            free(result_vector);
            char* path = "vector_column.c: In function create_vector_column()";
            error_t Error = ERROR_INVALID_DATA_TYPE;
            log_error(Error, path);
            return NULL;
    }
    result_vector->data = calloc(row, result_vector->type->size);
    if (result_vector->data == NULL) {
        char* path = "vector_column.c: In function create_vector_column()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    init_zeros_vector(&result_vector);
    return result_vector;
}

void free_vector(vector_column_t* vector) {
    if (vector == NULL) {
        char* path = "vector_column.c: In function free_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    if (vector->data == NULL) {
        char* path = "vector_column.c: In function free_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    free(vector->data);
    free(vector);
    return;
}

void* get_element_vector(const vector_column_t* vector, const int row) {
    if (vector == NULL || vector->data == NULL) {
        char* path = "vector_column.c: In function get_element_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (row < 0 || row >= vector->row) {
        char* path = "vector_column.c: In function get_element_vector()";
        error_t Error = ERROR_INVALID_MATRIX_INDICES;
        log_error(Error, path);
        return NULL;
    }
    void* element = (char*)vector->data + row * vector->type->size;
    return element; 
}

void set_element_vector(vector_column_t* vector, const int row, void* value) {
    if (vector == NULL || vector->data == NULL) {
        char* path = "vector_column.c: In function set_element_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    if (row < 0 || row >= vector->row) {
        char* path = "vector_column.c: In function set_element_vector()";
        error_t Error = ERROR_INVALID_MATRIX_INDICES;
        log_error(Error, path);
        return;
    }
    void* element = (char*)vector->data + row * vector->type->size;
    memcpy(element, value, vector->type->size);
    return;
}

void init_zeros_vector(vector_column_t** vector) {
    if (*vector == NULL || (*vector)->data == NULL) {
        char* path = "vector_column.c: In function init_zeros_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    for (int i = 0; i < (*vector)->row; i++) {
        for (int j = 0; j < 1; j++) {
            if (get_element_vector(*vector, i) == NULL) {
                char* path = "vector_column.c: In function init_zeros_vector()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            (*vector)->type->init_zero(get_element_vector(*vector, i));
        }
    }
    return;
}

char* toString_vector(const vector_column_t* vector) {
    if (vector == NULL) {
        char* path = "vector_column.c: In function toString_vector()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    size_t buff_size = 300;
    char* buff = (char*)malloc(buff_size);
    if (buff == NULL) {
        char* path = "vector_column.c: In function toString_vector()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    int cnt = snprintf(buff, buff_size, "[ ");
    for (int i = 0; i < vector->row; i++) {
        cnt += snprintf(buff + cnt, buff_size - cnt, "{");
        for (int j = 0; j < 1; j++) {
            if (get_element_vector(vector, i) == NULL) {
                char* path = "vector_column.c: In function toString_vector()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            vector->type->toString(get_element_vector(vector, i), &cnt, &buff, &buff_size);
        }
        cnt += snprintf(buff + cnt, buff_size - cnt, "}");
        if (i < vector->row - 1) {
            cnt += snprintf(buff + cnt, buff_size - cnt, " ");
        }
    }
    cnt += snprintf(buff + cnt, buff_size - cnt, " ]");
    return buff;
}