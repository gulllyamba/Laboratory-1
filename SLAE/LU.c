#include "LU.h"

#define EPSILON 1e-9

SquareMatrix_t* inverse_matrix(SquareMatrix_t* matrix) {
    SquareMatrix_t* inverse_matrix = create_matrix(matrix->size, matrix->type->type);
    for (int i = 0; i < inverse_matrix->size; i++) {
        double x = 1.0;
        set_element(inverse_matrix, i, i, &x);
    }
    for (int j = 0; j < matrix->size - 1; j++) {
        int cnt = 1;
        double diag = *(double*)get_element(matrix, j, j);
        for (int k = 0; k < matrix->size; k++) {
            if (*(double*)get_element(inverse_matrix, j , k) != 0) {
                double del = *(double*)get_element(inverse_matrix, j , k) / diag;
                set_element(inverse_matrix, j, k, &del);
            }
            if (*(double*)get_element(matrix, j , k) != 0) {
                double del = *(double*)get_element(matrix, j , k) / diag;
                set_element(matrix, j, k, &del);
            }
        }
        for (int i = j + 1; i < matrix->size; i++) {
            double temp = *(double*)get_element(matrix, i, j);
            for (int k = 0; k < matrix->size; k++) {
                double mat = *(double*)get_element(inverse_matrix, i, k) - temp * *(double*)get_element(inverse_matrix, i - cnt, k);
                set_element(inverse_matrix, i, k, &mat);
                mat = *(double*)get_element(matrix, i, k) - temp * *(double*)get_element(matrix, i - cnt, k);
                set_element(matrix, i, k, &mat);
            }
            cnt++;
        }
    }
    double diag = *(double*)get_element(matrix, matrix->size - 1, matrix->size - 1);
    for (int k = 0; k < matrix->size; k++) {
        double mat = *(double*)get_element(inverse_matrix, matrix->size - 1, k) / diag;
        set_element(inverse_matrix, matrix->size - 1, k, &mat);
        mat = *(double*)get_element(matrix, matrix->size - 1, k) / diag;
        set_element(matrix, matrix->size - 1, k, &mat);
    }
    for (int j = matrix->size - 1; j > 0 ; j--) {
        int cnt = 1;
        for (int i = j - 1; i >= 0; i--) {
            double temp = *(double*)get_element(matrix, i, j);
            for (int k = 0; k < matrix->size; k++) {
                double mat = *(double*)get_element(inverse_matrix, i, k) - temp * *(double*)get_element(inverse_matrix, i + cnt, k);
                set_element(inverse_matrix, i, k, &mat);
                mat = *(double*)get_element(matrix, i, k) - temp * *(double*)get_element(matrix, i + cnt, k);
                set_element(matrix, i, k, &mat);
            }
            cnt++;
        }
    }
    return inverse_matrix;
}

vector_column_t* count_vector_column(SquareMatrix_t* inverse, vector_column_t* b) {
    if (inverse == NULL || inverse->data == NULL) {
        char* path = "LU.c: In function create_vector_column()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (b == NULL || b->data == NULL) {
        char* path = "LU.c: In function create_vector_column()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    if (inverse->size != b->row) {
        char* path = "LU.c: In function create_vector_column()";
        error_t Error = ERROR_MISMATCH_MATRIX_SIZES;
        log_error(Error, path);
        return NULL;
    }
    vector_column_t* y = create_vector_column(b->row, b->type->type);
    if (y == NULL) {
        char* path = "LU.c: In function create_vector_column()";
        error_t Error = ERROR_NULL_POINTER;
        log_error(Error, path);
        return NULL;
    }
    for (int i = 0; i < inverse->size; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < inverse->size; k++) {
                void* product = NULL;
                while (product == NULL) {
                    product = calloc(1, y->type->size);
                    if (product == NULL) {
                        char* path = "LU.c: In function create_vector_column()";
                        error_t Error = ERROR_MEMORY_ALLOCATION;
                        log_error(Error, path);
                    }
                    else break;
                }
                if (get_element(inverse, i, k) == NULL || get_element_vector(y, k) == NULL || get_element_vector(b, k) == NULL) {
                    char* path = "LU.c: In function create_vector_column()";
                    error_t Error = ERROR_INVALID_MATRIX_INDICES;
                    log_error(Error, path);
                    free(product);
                    continue;
                }
                inverse->type->multiply(get_element(inverse, i, k), get_element_vector(b, k), product);
                inverse->type->sum(get_element_vector(y, i), product, get_element_vector(y, i));
                free(product);
            }
        }
    }
    return y;
}

void LU(SquareMatrix_t* A, SquareMatrix_t** L, SquareMatrix_t** U) {
    for (int i = 0; i < A->size; i++) {
        for (int j = 0; j < A->size; j++) {
            set_element(*U, i, j, get_element(A, i, j));
        }
    }
    for (int i = 0; i < A->size; i++) {
        for (int j = i; j < A->size; j++) {
            A->type->div(get_element(*U, j, i), get_element(*U, i, i), get_element(*L, j, i)); 
        }
    }
    for (int k = 1; k < A->size; k++) {
        for (int i = k - 1; i < A->size; i++) {
            for (int j = i; j < A->size; j++) {
                A->type->div(get_element(*U, j, i), get_element(*U, i, i), get_element(*L, j, i));
            }
        }

        for (int i = k; i < A->size; i++) {
            for (int j = k - 1; j < A->size; j++) {
                void* temp = calloc(1, sizeof(void));
                A->type->multiply(get_element(*L, i, k - 1), get_element(*U, k - 1, j), temp);
                A->type->diff(get_element(*U, i, j), temp, get_element(*U, i, j));
                free(temp);
            }
        }
    }
}

void init_matrix(SquareMatrix_t** A, int size, char* buff) {
    *A = create_matrix(size, DOUBLE);
    buff[strcspn(buff, "\n")] = '\0';
    char* token = strtok(buff, " ");
    int i = 0, j = 0;
    while (token != NULL) {
        double value = 0.0;
        int error1;
        int error2;
        if (sscanf(token, "%lf", &value) == 1 && sscanf(token, "%d+%di", &error1, &error2) != 2 && sscanf(token, "(%d+%di)", &error1, &error2) != 2);
        else {
            char* path = "LU.c: In function init_matrix()";
            error_t Error = ERROR_INVALID_DATA_TYPE;
            log_error(Error, path);
            j++;
            if (j == (*A)->size) {
                j = 0;
                i++;
            }
            token = strtok(NULL, " ");
            continue;
        }
        set_element(*A, i, j, &value);
        j++;
        if (j == (*A)->size) {
            j = 0;
            i++;
        }
        token = strtok(NULL, " ");
    }
    return;
}

double determinant_from_LU(SquareMatrix_t** matrix) {
    double determinant = 1;
    for (int i = 0; i < (*matrix)->size; i++) {
        determinant *= *(double*)get_element(*matrix, i, i);
    }
    return determinant;
}

int solutions(SquareMatrix_t* matrix) {
    if (fabs(determinant_from_LU(&matrix)) < EPSILON) {
        printf("Решения нет или бесконечно много решений\n");
        return 0;
    }
    else {
        printf("Существует единственное решение\n");
        return 1;
    }
}