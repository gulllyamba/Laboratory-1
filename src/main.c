#include "square_matrix.h"

// Использование библиотеки на примере типа INT

int main() {
    int SIZE;
    scanf("%d", &SIZE); // Ввод размера матриц

    SquareMatrix_t* A = create_matrix(SIZE, INT); // Инициализация матрицы A
    for (int i = 0; i < A->size; i++) { // Заполнение элементов матрицы A
        for (int j = 0; j < A->size; j++) {
            int x;
            scanf("%d", &x);
            set_element(A, i, j, &x);
        }
    }
    char* A_string = toString_matrix(A); // Перевод матрицы в строку
    printf("%s\n", A_string); // Вывод строки

    SquareMatrix_t* B = create_matrix(SIZE, INT); // Инициализация матрицы B
    for (int i = 0; i < B->size; i++) { // Заполнение элементов матрицы B
        for (int j = 0; j < B->size; j++) {
            int x;
            scanf("%d", &x);
            set_element(B, i, j, &x);
        }
    }
    char* B_string = toString_matrix(B);
    printf("%s\n", B_string);

    SquareMatrix_t* SUMM = sum_matrix(A, B); // Матрица SUMM - сумма матриц A и B
    char* SUMM_string = toString_matrix(SUMM);
    printf("%s\n", SUMM_string);

    SquareMatrix_t* MULT = multiply_matrix(A, B); // Матрица MULT - произведение матриц A и B
    char* MULT_string = toString_matrix(MULT); 
    printf("%s\n", MULT_string);

    int scalar;
    scanf("%d", &scalar); // Ввод значения для скаляра
    SquareMatrix_t* MULT_SC = multiply_matrix_scalar(A, &scalar); // Матрица MULT_SC - умножение матрицы A на скаляр (в данном случае - 5)
    char* MULT_SC_string = toString_matrix(MULT_SC);
    printf("%s\n", MULT_SC_string);

    int row;
    scanf("%d", &row); // Ввод строки, к которой будет прибавляться линейная комбинация остальных строк
    int* alhpas = (int*)calloc((A->size - 1), A->type->size); // Выделение памяти под массив коэффициентов для линейной комбинации и инициализация нулями
    for (int i = 0; i < A->size - 1; i++) { // Заполнение массива коэффициентов
        scanf("%d", &alhpas[i]);
    }
    SquareMatrix_t* LIN = linear_comb(A, row, (void*)alhpas); // Матрица SUMM - сумма матриц A и B
    char* LIN_string = toString_matrix(LIN);
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
}