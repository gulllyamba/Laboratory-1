#include "square_matrix.h"

void init_zeros_matrix(SquareMatrix_t** matrix);

SquareMatrix_t* create_matrix (const int size, const DataType_t type) {
    if (size < 1) {
        char* path = "square_matrix.c: In function create_matrix()";
        error_t Error = ERROR_INVALID_MATRIX_SIZE;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = (SquareMatrix_t*)calloc(1, sizeof(SquareMatrix_t));
    if (result_matrix == NULL)  {
        char* path = "square_matrix.c: In function create_matrix()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    result_matrix->size = size;
    switch (type)
    {
        case INT:
            result_matrix->type = &IntType;
            break;
        case DOUBLE:
            result_matrix->type = &DoubleType;
            break;
        case COMPLEX_INT:
            result_matrix->type = &ComplexIntType;
            break;
        case COMPLEX_DOUBLE:
            result_matrix->type = &ComplexDoubleType;
            break;
        default:
            free(result_matrix);
            char* path = "square_matrix.c: In function create_matrix()";
            error_t Error = ERROR_INVALID_DATA_TYPE;
            log_error(Error, path);
            return NULL;
    }
    result_matrix->data = calloc(size * size, result_matrix->type->size);
    if (result_matrix->data == NULL) {
        char* path = "square_matrix.c: In function create_matrix()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    init_zeros_matrix(&result_matrix);
    return result_matrix;
}

void free_matrix(SquareMatrix_t* matrix) {
    if (matrix == NULL) {
        char* path = "square_matrix.c: In function free_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    if (matrix->data == NULL) {
        char* path = "square_matrix.c: In function free_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    free(matrix->data);
    free(matrix);
    return;
}

void* get_element(const SquareMatrix_t* matrix, const int row, const int col) {
    if (matrix == NULL || matrix->data == NULL) {
        char* path = "ssquare_matrix.c: In function get_element()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (row < 0 || row >= matrix->size || col < 0 || col >= matrix->size) {
        char* path = "square_matrix.c: In function get_element()";
        error_t Error = ERROR_INVALID_MATRIX_INDICES;
        log_error(Error, path);
        return NULL;
    }
    void* element = (char*)matrix->data + (row * matrix->size + col) * matrix->type->size;
    return element; 
}

void set_element(SquareMatrix_t* matrix, const int row, const int col, void* value) {
    if (matrix == NULL || matrix->data == NULL) {
        char* path = "square_matrix.c: In function set_element()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    if (row < 0 || row >= matrix->size || col < 0 || col >= matrix->size) {
        char* path = "square_matrix.c: In function set_element()";
        error_t Error = ERROR_INVALID_MATRIX_INDICES;
        log_error(Error, path);
        return;
    }
    void* element = (char*)matrix->data + (row * matrix->size + col) * matrix->type->size;
    memcpy(element, value, matrix->type->size);
    return;
}

void init_zeros_matrix(SquareMatrix_t** matrix) {
    if (*matrix == NULL || (*matrix)->data == NULL) {
        char* path = "square_matrix.c: In function init_zeros_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return;
    }
    for (int i = 0; i < (*matrix)->size; i++) {
        for (int j = 0; j < (*matrix)->size; j++) {
            if (get_element(*matrix, i, j) == NULL) {
                char* path = "square_matrix.c: In function multiply_matrix()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            (*matrix)->type->init_zero(get_element(*matrix, i, j));
        }
    }
    return;
}

// void print_matrix(const SquareMatrix_t* matrix) {
//     if (matrix == NULL || matrix->data == NULL) {
//         printf("Вывести нечего\n"); //ошибка
//         return;
//     }
//     for (int i = 0; i < matrix->size; i++) {
//         for (int j = 0; j < matrix->size; j++) {
//             matrix->type->print(get_element(matrix, i, j));
//         }
//         printf("\n");
//     }
//     return;
// }

char* toString_matrix(const SquareMatrix_t* matrix) {
    if (matrix == NULL) {
        char* path = "square_matrix.c: In function toString_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    size_t buff_size = 300;
    char* buff = (char*)malloc(buff_size);
    if (buff == NULL) {
        char* path = "square_matrix.c: In function toString_matrix()";
        error_t Error = ERROR_MEMORY_ALLOCATION;
        log_error(Error, path);
        return NULL;
    }
    int cnt = snprintf(buff, buff_size, "[ ");
    for (int i = 0; i < matrix->size; i++) {
        cnt += snprintf(buff + cnt, buff_size - cnt, "{");
        for (int j = 0; j < matrix->size; j++) {
            if (get_element(matrix, i, j) == NULL) {
                char* path = "square_matrix.c: In function toString_matrix()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            matrix->type->toString(get_element(matrix, i, j), &cnt, &buff, &buff_size);
            if (j < matrix->size - 1) {
                cnt += snprintf(buff + cnt, buff_size - cnt, ", ");
            }
        }
        cnt += snprintf(buff + cnt, buff_size - cnt, "}");
        if (i < matrix->size - 1) {
            cnt += snprintf(buff + cnt, buff_size - cnt, " ");
        }
    }
    cnt += snprintf(buff + cnt, buff_size - cnt, " ]");
    return buff;
}

SquareMatrix_t* sum_matrix(const SquareMatrix_t* A, const SquareMatrix_t* B) {
    if (A == NULL || A->data == NULL) {
        char* path = "square_matrix.c: In function sum_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (B == NULL || B->data == NULL) {
        char* path = "square_matrix.c: In function sum_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (A->size != B->size) {
        char* path = "square_matrix.c: In function sum_matrix()";
        error_t Error = ERROR_MISMATCH_MATRIX_SIZES;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = create_matrix(A->size, A->type->type);
    if (result_matrix == NULL) {
        char* path = "square_matrix.c: In function sum_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int i = 0; i < A->size; i++) {
        for (int j = 0; j < A->size; j++) {
            void* value_a = get_element(A, i, j);
            void* value_b = get_element(B, i, j);
            if (value_a == NULL || value_b == NULL) {
                char* path = "square_matrix.c: In function sum_matrix()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            void* value_result = get_element(result_matrix, i, j);
            if (value_result == NULL) {
                char* path = "square_matrix.c: In function sum_matrix()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            A->type->sum(value_a, value_b, value_result);
        }
    }
    return result_matrix;
}

SquareMatrix_t* multiply_matrix(const SquareMatrix_t* A, const SquareMatrix_t* B) {
    if (A == NULL || A->data == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (B == NULL || B->data == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (A->size != B->size) {
        char* path = "square_matrix.c: In function multiply_matrix()";
        error_t Error = ERROR_MISMATCH_MATRIX_SIZES;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = create_matrix(A->size, A->type->type);
    if (result_matrix == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int i = 0; i < A->size; i++) {
        for (int j = 0; j < B->size; j++) {
            for (int k = 0; k < A->size; k++) {
                void* product = NULL;
                while (product == NULL) {
                    product = calloc(1, result_matrix->type->size);
                    if (product == NULL) {
                        char* path = "square_matrix.c: In function multiply_matrix()";
                        error_t Error = ERROR_MEMORY_ALLOCATION;
                        log_error(Error, path);
                    }
                    else break;
                }
                if (get_element(A, i, k) == NULL || get_element(B, k, j) == NULL || get_element(result_matrix, i, j) == NULL) {
                    char* path = "square_matrix.c: In function multiply_matrix()";
                    error_t Error = ERROR_INVALID_MATRIX_INDICES;
                    log_error(Error, path);
                    free(product);
                    continue;
                }
                A->type->multiply(get_element(A, i, k), get_element(B, k, j), product);
                A->type->sum(get_element(result_matrix, i, j), product, get_element(result_matrix, i, j));
                free(product);
            }
        }
    }
    return result_matrix;
}

SquareMatrix_t* transposition(const SquareMatrix_t* matrix) {
    if (matrix == NULL || matrix->data == NULL) {
        char* path = "square_matrix.c: In function transposition()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = create_matrix(matrix->size, matrix->type->type);
    if (result_matrix == NULL) {
        char* path = "square_matrix.c: In function transposition_matrix()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            if (get_element(matrix, i, j) == NULL) {
                char* path = "square_matrix.c: In function sum_matrix()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            set_element(result_matrix, j, i, get_element(matrix, i, j));
        }
    }
    return result_matrix;
}

SquareMatrix_t* multiply_matrix_scalar(const SquareMatrix_t* matrix, void* scalar) {
    if (matrix == NULL || matrix->data == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix_scalar()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = create_matrix(matrix->size, matrix->type->type);
    if (result_matrix == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix_scalar()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int i = 0; i < result_matrix->size; i++) {
        for (int j = 0; j < result_matrix->size; j++) {
            if (get_element(matrix, i, j) == NULL || get_element(result_matrix, i, j) == NULL) {
                char* path = "square_matrix.c: In function multiply_matrix_scalar()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            result_matrix->type->multiply_scalar(get_element(matrix, i, j), scalar, get_element(result_matrix, i, j));
        }
    }
    return result_matrix;
}

SquareMatrix_t* linear_comb(const SquareMatrix_t* matrix, const int row, void* alhpas) {
    if (row < 0 || row >= matrix->size) {
        char* path = "square_matrix.c: In function linear_comb()";
        error_t Error = ERROR_INVALID_MATRIX_INDICES;
        log_error(Error, path);
        return NULL;
    }
    if (matrix == NULL || matrix->data == NULL) {
        char* path = "square_matrix.c: In function linear_comb()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    SquareMatrix_t* result_matrix = create_matrix(matrix->size, matrix->type->type);
    if (result_matrix == NULL) {
        char* path = "square_matrix.c: In function multiply_matrix_scalar()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int j = 0; j < matrix->size; j++) {
        int k = 0;
        if (get_element(matrix, row, j) == NULL) {
            char* path = "square_matrix.c: In function linear_comb()";
            error_t Error = ERROR_INVALID_MATRIX_INDICES;
            log_error(Error, path);
            continue;
        }
        void* element = get_element(matrix, row, j);
        for (int i = 0; i < matrix->size; i++) {
            if (get_element(matrix, i, j) == NULL) {
                char* path = "square_matrix.c: In function linear_comb()";
                error_t Error = ERROR_INVALID_MATRIX_INDICES;
                log_error(Error, path);
                continue;
            }
            set_element(result_matrix, i, j, get_element(matrix, i, j));
            if (i == row) continue;
            void* product = NULL;
                while (product == NULL) {
                    product = calloc(1, result_matrix->type->size);
                    if (product == NULL) {
                        char* path = "square_matrix.c: In function linear_comb()";
                        error_t Error = ERROR_MEMORY_ALLOCATION;
                        log_error(Error, path);
                    }
                    else break;
                }
            *(int*)product = 0;
            void* target = get_element(matrix, i, j);
            result_matrix->type->multiply_scalar(target, (char*)alhpas + k * result_matrix->type->size_for_linear_combination, product);
            result_matrix->type->sum(element, product, element);
            free(product);
            k++;
        }
        set_element(result_matrix, row, j, element);
    }
    return result_matrix;
}