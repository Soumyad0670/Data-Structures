#include <stdio.h>

int main() {
    int rows, cols;
    int mat1[100][100], mat2[100][100];
    
    // Taking input for matrix size
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Taking input for first matrix
    printf("\nEnter elements for first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    
    // Taking input for second matrix
    printf("\nEnter elements for second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Checking if matrices are equal
    int areEqual = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                areEqual = 0;
                break;
            }
        }
        if (!areEqual) {
            break;
        }
    }
    
    if (areEqual) {
        printf("\nThe matrices are equal.\n");
    } else {
        printf("\nThe matrices are not equal.\n");
    }
    
    return 0;
}