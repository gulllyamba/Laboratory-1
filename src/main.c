#include "square_matrix.h"

int main() {
    // Использование библиотеки на примере типа INT
    int SIZE;
    scanf("%d", &SIZE); // Ввод размера матриц

    SQUARE_MATRIX(A, SIZE, INT); // Инициализация матрицы A
    for (int i = 0; i < A->size; i++) { // Заполнение элементов матрицы A
        for (int j = 0; j < A->size; j++) {
            int x;
            scanf("%d", &x);
            set_element(A, i, j, &x);
        }
    }
    TO_STRING(A_string, A); // Перевод матрицы в строку
    printf("%s\n", A_string); // Вывод строки

    SQUARE_MATRIX(B, SIZE, INT); // Инициализация матрицы B
    for (int i = 0; i < B->size; i++) { // Заполнение элементов матрицы B
        for (int j = 0; j < B->size; j++) {
            int x;
            scanf("%d", &x);
            set_element(B, i, j, &x); // Установка элемента x на [i][j] место
        }
    }
    TO_STRING(B_string, B);
    printf("%s\n", B_string);

    SUMM_MATRICES(SUMM, A, B); // Матрица SUMM - сумма матриц A и B
    TO_STRING(SUMM_string, SUMM);
    printf("%s\n", SUMM_string);

    MULTIPLY_MATRICES(MULT, A, B); // Матрица MULT - произведение матриц A и B
    TO_STRING(MULT_string, MULT);
    printf("%s\n", MULT_string);

    int scalar;
    scanf("%d", &scalar); // Ввод значения для скаляра
    MULTIPLY_SCALAR_MATRICES(MULT_SC, A, &scalar); // Матрица MULT_SC - умножение матрицы A на скаляр (в данном случае - 5)
    TO_STRING(MULT_SC_string, MULT_SC);
    printf("%s\n", MULT_SC_string);

    int row;
    scanf("%d", &row); // Ввод строки, к которой будет прибавляться линейная комбинация остальных строк
    int* alhpas = (int*)calloc((A->size - 1), A->type->size); // Выделение памяти под массив коэффициентов для линейной комбинации и инициализация нулями
    for (int i = 0; i < A->size - 1; i++) { // Заполнение массива коэффициентов
        scanf("%d", &alhpas[i]);
    }
    LINEAR_COMB(LIN, A, row, (void*)alhpas);// Матрица SUMM - сумма матриц A и B
    TO_STRING(LIN_string, LIN);
    printf("%s\n", LIN_string);

    free(A_string); // освобождение памяти, занятой под строки
    free(B_string);
    free(SUMM_string);
    free(MULT_string);
    free(MULT_SC_string);
    free(LIN_string);

    free_matrix(A); // освобождение памяти, занятой под матрицы
    free_matrix(B);
    free_matrix(SUMM);
    free_matrix(MULT);
    free_matrix(MULT_SC);
    free_matrix(LIN);

    //////////////////////////////////////////////////////////////////////////////////////////////////

    // Использование библиотеки на примере типа COMPLEX_INT
    scanf("%d", &SIZE); // Ввод размера матриц

    SQUARE_MATRIX(A_CMP, SIZE, COMPLEX_INT); // Инициализация матрицы A
    for (int i = 0; i < A_CMP->size; i++) { // Заполнение элементов матрицы A
        for (int j = 0; j < A_CMP->size; j++) {
            int Re, Im;
            scanf("%d %d", &Re, &Im);
            COMPLEX_INT(value_A, &Re, &Im); // Создание комплексного числа
            set_element(A_CMP, i, j, (void*)value_A); // Установка комплексного числа value на [i][j] место
            free_complex_int(value_A); // Освобождение памяти, занятой под комплексное число
        }
    }
    TO_STRING(A_CMP_string, A_CMP); // Перевод матрицы в строку
    printf("%s\n", A_CMP_string); // Вывод строки

    SQUARE_MATRIX(B_CMP, SIZE, COMPLEX_INT); // Инициализация матрицы B
    for (int i = 0; i < B_CMP->size; i++) { // Заполнение элементов матрицы B
        for (int j = 0; j < B_CMP->size; j++) {
            int Re, Im;
            scanf("%d %d", &Re, &Im);
            COMPLEX_INT(value_B, &Re, &Im);
            set_element(B_CMP, i, j, (void*)value_B);
            free_complex_int(value_B);
        }
    }
    TO_STRING(B_CMP_string, B_CMP);
    printf("%s\n", B_CMP_string);

    SUMM_MATRICES(SUMM_CMP, A_CMP, B_CMP); // Матрица SUMM - сумма матриц A и B
    TO_STRING(SUMM_CMP_string, SUMM_CMP);
    printf("%s\n", SUMM_CMP_string);

    MULTIPLY_MATRICES(MULT_CMP, A_CMP, B_CMP); // Матрица MULT - произведение матриц A и B
    TO_STRING(MULT_CMP_string, MULT_CMP);
    printf("%s\n", MULT_CMP_string);

    int scalar_CMP;
    scanf("%d", &scalar_CMP); // Ввод значения для скаляра
    MULTIPLY_SCALAR_MATRICES(MULT_SC_CMP, A_CMP, &scalar_CMP); // Матрица MULT_SC - умножение матрицы A на скаляр (в данном случае - 5)
    TO_STRING(MULT_SC_CMP_string, MULT_SC_CMP);
    printf("%s\n", MULT_SC_CMP_string);

    int row_CMP;
    scanf("%d", &row_CMP); // Ввод строки, к которой будет прибавляться линейная комбинация остальных строк
    int* alhpas_CMP = (int*)calloc((A_CMP->size - 1), A_CMP->type->size); // Выделение памяти под массив коэффициентов для линейной комбинации и инициализация нулями
    for (int i = 0; i < A_CMP->size - 1; i++) { // Заполнение массива коэффициентов
        scanf("%d", &alhpas_CMP[i]);
    }
    LINEAR_COMB(LIN_CMP, A_CMP, row_CMP, (void*)alhpas_CMP);// Матрица SUMM - сумма матриц A и B
    TO_STRING(LIN_CMP_string, LIN_CMP);
    printf("%s\n", LIN_CMP_string);

    free(A_CMP_string); // Освобождение памяти, занятой под строки
    free(B_CMP_string);
    free(SUMM_CMP_string);
    free(MULT_CMP_string);
    free(MULT_SC_CMP_string);
    free(LIN_CMP_string);

    free_matrix(A_CMP); // Освобождение памяти, занятой под матрицы
    free_matrix(B_CMP);
    free_matrix(SUMM_CMP);
    free_matrix(MULT_CMP);
    free_matrix(MULT_SC_CMP);
    free_matrix(LIN_CMP);
}