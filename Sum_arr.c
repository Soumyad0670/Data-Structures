#include<stdio.h>
int main(){
    int i, j, n;
    int mat1[n][n], mat2[n][n], sum[n][n];
    printf("Enter the order of the matrix");
    scanf("%d",&n);
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("Sum of matrices:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}