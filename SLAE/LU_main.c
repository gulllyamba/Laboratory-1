#include "LU.h"

int main() {
    char buff[100];
    int size;
    FILE* file = fopen("SLAE/input.txt", "r");
    if (file == NULL) {
        char* path = "LU_main.c";
        error_t Error = ERROR_FILE_READ;
        log_error(Error, path);
        return 0;
    }
    fgets(buff, sizeof(buff), file);
    buff[strcspn(buff, "\n")] = '\0';
    sscanf(buff, "%d", &size);
    printf("Размер матриц: %d\n", size);

    SquareMatrix_t* A;
    SquareMatrix_t* L = create_matrix(size, DOUBLE);
    SquareMatrix_t* U = create_matrix(size, DOUBLE);
    vector_column_t* b = create_vector_column(size, DOUBLE);
    SquareMatrix_t* inverse_L;
    SquareMatrix_t* inverse_U;
    vector_column_t* y;
    vector_column_t* x;

    fgets(buff, sizeof(buff), file);
    init_matrix(&A, size, buff);

    LU(A, &L, &U);

    if (!solutions(U)) return 0;

    SquareMatrix_t* R = multiply_matrix(L, U);

    char* A_matrix = toString_matrix(A);
    printf("Исходная матрица: %s\n", A_matrix);

    char* L_matrix = toString_matrix(L);
    printf("L матрица: %s\n", L_matrix); 
    
    char* U_matrix = toString_matrix(U);
    printf("U матрица: %s\n", U_matrix);
    
    char* R_matrix = toString_matrix(R);
    printf("Проверка: %s\n", R_matrix);

    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strcmp(buff, "FREE_COEFFICIENTS\n") == 0) {
            fgets(buff, sizeof(buff), file);
            char* token = strtok(buff, " ");
            int row = 0;
            while (token != NULL && get_element_vector(b, row) != NULL) {
                double value;
                sscanf(token, "%lf", &value);
                set_element_vector(b, row, &value);
                token = strtok(NULL, " ");
                row++;
            }
            char* B_vector = toString_vector(b);
            printf("B (Свободные коэффициенты): %s\n", B_vector);

            inverse_L = inverse_matrix(L);
            char* inverse_L_matrix = toString_matrix(inverse_L);
            printf("Обратная матрица L (L^-1): %s\n", inverse_L_matrix);

            inverse_U = inverse_matrix(U);
            char* inverse_U_matrix = toString_matrix(inverse_U);
            printf("Обратная матрица U (U^-1): %s\n", inverse_U_matrix);

            y = count_vector_column(inverse_L, b);
            char* Y_vector = toString_vector(y);
            printf("Y: %s\n", Y_vector);

            x = count_vector_column(inverse_U, y);
            char* X_vector = toString_vector(x);
            printf("X (Корни): %s\n", X_vector);

            free(inverse_L_matrix);
            free(inverse_U_matrix);
            free(B_vector);
            free(Y_vector);
            free(X_vector);
        }
    }

    free(A_matrix);
    free(L_matrix);
    free(U_matrix);
    free(R_matrix);

    free_matrix(A);
    free_matrix(L);
    free_matrix(U);
    free_matrix(R);
    free_matrix(inverse_L);
    free_matrix(inverse_U);
    free_vector(y);
    free_vector(x);
    return 0;
}