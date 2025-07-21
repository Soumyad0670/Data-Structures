#include <stdio.h>
int main()
{
    int i, j, k, sum;
    int p, q, r, s;
    printf("enter type of matrix of A(p*q):");
    scanf("%d %d", &p, &q);
    printf("enter type of matrix of B(r*s):");
    scanf("%d %d", &r, &s);
    int a[p][q], b[r][s], c[p][s];
    if (q != r)
    {
        printf("invalid for matrix multipication,try again!\n");
        return 0;
    }
    else
    {

        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("enter matrix A%d%d:", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < s; j++)
            {
                printf("enter matrix B%d%d:", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }
        printf("New matrix:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < s; j++)
            {
                sum = 0;
                for (k = 0; k < q; k++)
                {
                    sum = sum + (a[i][k] * b[k][j]);
                }
                c[i][j] = sum;
            }
        }

        for (i = 0; i < p; i++)
        {
            for (j = 0; j < s; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}