#include <stdio.h>
#include <stdlib.h>
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
int main() {
    FILE* file = fopen("matrices.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    int rows1, cols1, rows2, cols2;
    fscanf(file, "%d %d", &rows1, &cols1);
    int** matrix1 = allocateMatrix(rows1, cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            fscanf(file, "%d", &matrix1[i][j]);
        }
    }
    fscanf(file, "%d %d", &rows2, &cols2);
    int** matrix2 = allocateMatrix(rows2, cols2);
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            fscanf(file, "%d", &matrix2[i][j]);
        }
    }
    fclose(file);
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    return 0;
}