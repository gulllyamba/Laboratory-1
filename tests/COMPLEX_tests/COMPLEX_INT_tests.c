#include "COMPLEX_INT_tests.h"

void init_matrix_complex_int_tests(SquareMatrix_t** A, int size, char* buff) {
    *A = create_matrix(size, COMPLEX_INT);
    buff[strcspn(buff, "\n")] = '\0';
    char* token = strtok(buff, " ");
    int i = 0, j = 0;
    while (token != NULL) {
        Complex_int_t value;
        int error1;
        int error2;
        int error3;
        int error4;
        if (sscanf(token, "(%d+%di)", &value.Re, &value.Im) == 2 && sscanf(token, "%d.%d", &error1, &error2) != 2 && sscanf(token, "%d+%di", &error1, &error2) != 2 && sscanf(token, "%d", &error1) != 1 && sscanf(token, "(%d.%d+%d.%di)", &error1, &error2, &error3, &error4) != 4);
        else {
            char* path = "COMPLEX_INT_tests.c: In function init_matrix_complex_int_tests()";
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

void sum_matrix_complex_int_tests(SquareMatrix_t* A, SquareMatrix_t* B, SquareMatrix_t** result, char* buff) {
    *result = sum_matrix(A, B);
    printf("Сумма матриц:\n");
    printf("Ожидание:\n");
    buff[strcspn(buff, "\n")] = '\0';
    char* token = strtok(buff, " ");
    int i = 0, j = 0;
    bool state = 1;
    while (token != NULL && get_element(*result, i, j) != NULL) {
        printf("%s ", token);
        Complex_int_t value;
        sscanf(token, "(%d+%di)", &value.Re, &value.Im);
        if (value.Re == ((Complex_int_t*)get_element(*result, i, j))->Re && value.Im == ((Complex_int_t*)get_element(*result, i, j))->Im);
        else state = 0;
        j++;
        if (j == (*result)->size) {
            printf("\n");
            j = 0;
            i++;
        }
        token = strtok(NULL, " ");
    }
    printf("Реальность:\n");
    //print_matrix(*result);
    char* answer = toString_matrix(*result);
    if (answer != NULL) {
        printf("%s\n", answer);
        free(answer);
    }
    else {
        printf("----------------------------\n");
        return;
    }
    if (state) printf("CORRECT\n");
    else printf("NOT CORRECT\n");
    printf("----------------------------\n");
}

void multiply_matrix_complex_int_tests(SquareMatrix_t* A, SquareMatrix_t* B, SquareMatrix_t** result, char* buff) {
    *result = multiply_matrix(A, B);
    printf("Произведение матриц:\n");
    printf("Ожидание:\n");
    buff[strcspn(buff, "\n")] = '\0';
    char* token = strtok(buff, " ");
    int i = 0, j = 0;
    bool state = 1;
    while (token != NULL && get_element(*result, i, j) != NULL) {
        printf("%s ", token);
        Complex_int_t value;
        sscanf(token, "(%d+%di)", &value.Re, &value.Im);
        if (value.Re == ((Complex_int_t*)get_element(*result, i, j))->Re && value.Im == ((Complex_int_t*)get_element(*result, i, j))->Im);
        else state = 0;
        j++;
        if (j == (*result)->size) {
            printf("\n");
            j = 0;
            i++;
        }
        token = strtok(NULL, " ");
    }
    printf("Реальность:\n");
    //print_matrix(*result);
    char* answer = toString_matrix(*result);
    if (answer != NULL) {
        printf("%s\n", answer);
        free(answer);
    }
    else {
        printf("----------------------------\n");
        return;
    }
    if (state) printf("CORRECT\n");
    else printf("NOT CORRECT\n");
    printf("----------------------------\n");
}

void multiply_scalar_matrix_complex_int_tests(SquareMatrix_t* A, SquareMatrix_t** result, char* buff) {
    printf("Произведение матрицы на скаляр:\n");
    buff[strcspn(buff, "\n")] = '\0';
    char* token = strtok(buff, " ");
    int value;
    sscanf(token, "%d", &value);
    printf("Скаляр: %d\n", value);
    printf("Ожидание:\n");
    void* scalar = &value;
    *result = multiply_matrix_scalar(A, scalar);
    int i = 0, j = 0;
    bool state = 1;
    token = strtok(NULL, " ");
    while (token != NULL && get_element(*result, i, j) != NULL) {
        printf("%s ", token);
        Complex_int_t value;
        sscanf(token, "(%d+%di)", &value.Re, &value.Im);
        if (value.Re == ((Complex_int_t*)get_element(*result, i, j))->Re && value.Im == ((Complex_int_t*)get_element(*result, i, j))->Im);
        else state = 0;
        j++;
        if (j == (*result)->size) {
            printf("\n");
            j = 0;
            i++;
        }
        token = strtok(NULL, " ");
    }
    printf("Реальность:\n");
    //print_matrix(*result);
    char* answer = toString_matrix(*result);
    if (answer != NULL) {
        printf("%s\n", answer);
        free(answer);
    }
    else {
        printf("----------------------------\n");
        return;
    }
    if (state) printf("CORRECT\n");
    else printf("NOT CORRECT\n");
    printf("----------------------------\n");
}

void linear_combination_matrix_complex_int_tests(SquareMatrix_t* A, SquareMatrix_t** result, char* buff) {
    printf("Линейная комбинация:\n");
    char* token = strtok(buff, " ");
    int row = 0;
    int i = 0, j = 0;
    sscanf(token, "%d", &row);
    printf("Строка: %d\nКоэффициенты: ", row);
    token = strtok(NULL, " ");
    int* alhpas_int = (int*)calloc((A->size - 1), sizeof(int));
    while (token != NULL && i < A->size - 1) {
        sscanf(token, "%d", &alhpas_int[i]);
        printf("%d ", alhpas_int[i]);
        i++;
        token = strtok(NULL, " ");
    }
    printf("\nОжидание\n");
    void* alhpas = alhpas_int;
    *result = linear_comb(A, row, alhpas);
    free(alhpas_int);
    i = j = 0;
    bool state = 1;
    while (token != NULL && get_element(*result, i, j) != NULL) {
        printf("%s ", token);
        Complex_int_t value;
        sscanf(token, "(%d+%di)", &value.Re, &value.Im);
        if (value.Re == ((Complex_int_t*)get_element(*result, i, j))->Re && value.Im == ((Complex_int_t*)get_element(*result, i, j))->Im);
        else state = 0;
        j++;
        if (j == (*result)->size) {
            printf("\n");
            j = 0;
            i++;
        }
        token = strtok(NULL, " ");
    }
    printf("Реальность:\n");
    //print_matrix(*result);
    char* answer = toString_matrix(*result);
    if (answer != NULL) {
        printf("%s\n", answer);
        free(answer);
    }
    else {
        printf("----------------------------\n");
        return;
    }
    if (state) printf("CORRECT\n");
    else printf("NOT CORRECT\n");
    printf("----------------------------\n");
}