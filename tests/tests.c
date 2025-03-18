#include "../src/square_matrix.h"
#include "INT_tests/INT_tests.h"
#include "DOUBLE_tests/DOUBLE_tests.h"
#include "COMPLEX_tests/COMPLEX_INT_tests.h"
#include "COMPLEX_tests/COMPLEX_DOUBLE_tests.h"

int main() {
    SquareMatrix_t* A;
    SquareMatrix_t* B;
    SquareMatrix_t* result;

    char buff[200];
    int MAX_COL;
    ////////////////////////////////////////////////////////
    printf("----------------------------\nТесты для INT:\n----------------------------\n");
    FILE* file = fopen("tests/INT_tests/INT_input.txt", "r");
    if (file == NULL) {
        char* path = "main.c";
        error_t Error = ERROR_FILE_READ;
        log_error(Error, path);
        return 0;
    }
    fgets(buff, sizeof(buff), file);
    buff[strcspn(buff, "\n")] = '\0';
    sscanf(buff, "%d", &MAX_COL);
    printf("Размер матриц: %d\n", MAX_COL);

    fgets(buff, sizeof(buff), file);
    init_matrix_int_tests(&A, MAX_COL, buff);
    fgets(buff, sizeof(buff), file);
    init_matrix_int_tests(&B, MAX_COL, buff);
    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strcmp(buff, "SUMM\n") == 0) {
            fgets(buff, sizeof(buff), file);
            sum_matrix_int_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_matrix_int_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY_SCALAR\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_scalar_matrix_int_tests(A, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "LINEAR_COMBINATION\n") == 0) {
            fgets(buff, sizeof(buff), file);
            linear_combination_matrix_int_tests(A, &result, buff);
            if (result != NULL) free_matrix(result);
        }
    }
    fclose(file);
    free_matrix(A);
    free_matrix(B);
    //////////////////////////////////////////////////////////
    printf("Тесты для DOUBLE:\n----------------------------\n");
    file = fopen("tests/DOUBLE_tests/DOUBLE_input.txt", "r");
    if (file == NULL) {
        char* path = "main.c";
        error_t Error = ERROR_FILE_READ;
        log_error(Error, path);
        return 0;
    }
    fgets(buff, sizeof(buff), file);
    buff[strcspn(buff, "\n")] = '\0';
    sscanf(buff, "%d", &MAX_COL);
    printf("Размер матриц: %d\n", MAX_COL);

    fgets(buff, sizeof(buff), file);
    init_matrix_double_tests(&A, MAX_COL, buff);
    fgets(buff, sizeof(buff), file);
    init_matrix_double_tests(&B, MAX_COL, buff);
    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strcmp(buff, "SUMM\n") == 0) {
            fgets(buff, sizeof(buff), file);
            sum_matrix_double_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_matrix_double_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY_SCALAR\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_scalar_matrix_double_tests(A, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "LINEAR_COMBINATION\n") == 0) {
            fgets(buff, sizeof(buff), file);
            linear_combination_matrix_double_tests(A, &result, buff);
            free_matrix(result);
        }
    }
    fclose(file);
    free_matrix(A);
    free_matrix(B);
    //////////////////////////////////////////////////////////
    printf("Тесты для COMPLEX_INT:\n----------------------------\n");
    file = fopen("tests/COMPLEX_tests/COMPLEX_INT_input.txt", "r");
    if (file == NULL) {
        char* path = "main.c";
        error_t Error = ERROR_FILE_READ;
        log_error(Error, path);
        return 0;
    }
    fgets(buff, sizeof(buff), file);
    buff[strcspn(buff, "\n")] = '\0';
    sscanf(buff, "%d", &MAX_COL);
    printf("Размер матриц: %d\n", MAX_COL);

    fgets(buff, sizeof(buff), file);
    init_matrix_complex_int_tests(&A, MAX_COL, buff);
    fgets(buff, sizeof(buff), file);
    init_matrix_complex_int_tests(&B, MAX_COL, buff);
    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strcmp(buff, "SUMM\n") == 0) {
            fgets(buff, sizeof(buff), file);
            sum_matrix_complex_int_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_matrix_complex_int_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY_SCALAR\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_scalar_matrix_complex_int_tests(A, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "LINEAR_COMBINATION\n") == 0) {
            fgets(buff, sizeof(buff), file);
            linear_combination_matrix_complex_int_tests(A, &result, buff);
            free_matrix(result);
        }
    }
    fclose(file);
    free_matrix(A);
    free_matrix(B);
    //////////////////////////////////////////////////////////
    printf("Тесты для COMPLEX_DOUBLE:\n----------------------------\n");
    file = fopen("tests/COMPLEX_tests/COMPLEX_DOUBLE_input.txt", "r");
    if (file == NULL) {
        char* path = "main.c";
        error_t Error = ERROR_FILE_READ;
        log_error(Error, path);
        return 0;
    }
    fgets(buff, sizeof(buff), file);
    buff[strcspn(buff, "\n")] = '\0';
    sscanf(buff, "%d", &MAX_COL);
    printf("Размер матриц: %d\n", MAX_COL);

    fgets(buff, sizeof(buff), file);
    init_matrix_complex_double_tests(&A, MAX_COL, buff);
    fgets(buff, sizeof(buff), file);
    init_matrix_complex_double_tests(&B, MAX_COL, buff);
    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strcmp(buff, "SUMM\n") == 0) {
            fgets(buff, sizeof(buff), file);
            sum_matrix_complex_double_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_matrix_complex_double_tests(A, B, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "MULTIPLY_SCALAR\n") == 0) {
            fgets(buff, sizeof(buff), file);
            multiply_scalar_matrix_complex_double_tests(A, &result, buff);
            free_matrix(result);
        }
        else if (strcmp(buff, "LINEAR_COMBINATION\n") == 0) {
            fgets(buff, sizeof(buff), file);
            linear_combination_matrix_complex_double_tests(A, &result, buff);
            free_matrix(result);
        }
    }
    fclose(file);
    free_matrix(A);
    free_matrix(B);
    return 0;
}