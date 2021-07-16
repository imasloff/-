#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("matr[%d][%d] = ", i, j);
            scanf_s("%d", &matr[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}
