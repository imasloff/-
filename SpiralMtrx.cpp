#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int h, w;
    printf("Enter the height of your matrix: ");
    scanf_s("%d", &h);
    printf("Enter the width of your matrix: ");
    scanf_s("%d", &w);
    int **matr = (int**)calloc(h, sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        matr[i] = (int*)calloc(w, sizeof(int));
    }
    int startCol = 0, endCol = w-1, startRow = 0, endRow = h-1;

    while ((startCol <= endCol) && (startRow <= endRow))
    {
        for (int i = startCol; i <= endCol; i++)
        {
            printf("matr[%d][%d] = ", startRow, i);
            scanf_s("%d", &matr[startRow][i]);
        }
        startRow++;
        for (int i = startRow; i <= endRow; i++)
        {
            printf("matr[%d][%d] = ", i, endCol);
            scanf_s("%d", &matr[i][endCol]);
        }
        endCol--;
        for (int i = endCol; i >= startCol; i--)
        {
            printf("matr[%d][%d] = ", endRow, i);
            scanf_s("%d", &matr[endRow][i]);
        }
        endRow--;
        for (int i = endRow; i >= startRow; i--)
        {
            printf("matr[%d][%d] = ", i, startCol);
            scanf_s("%d", &matr[i][startCol]);
        }
        startCol++;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < h; i++)
        free(matr[i]);
    free(matr);
}
