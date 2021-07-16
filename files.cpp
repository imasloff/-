#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int pnumber = 0, snumber = 0, n;
    int arr[10], matr[5][5];
    FILE* file;
    //7.1
    file = fopen("number.txt", "w");
    printf("Enter the number\n");
    scanf_s("%d", &pnumber);
    fprintf(file, "\n%d", pnumber);
    fclose(file);
    //7.2
    file = fopen("number.txt", "r");
    fscanf(file, "%d", &snumber);
    printf("%d\n", snumber);
    fclose(file);
    //7.3
    file = fopen("number.txt", "w");
    printf("Enter the amount of numbers u want to put into the file: ");
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the %d number: ", i);
        scanf_s("%d", &pnumber);
        fprintf(file, "%d", pnumber);
        fprintf(file, "%c", '\n');
    }
    fclose(file);
    //7.4
    file = fopen("number.txt", "r");
    printf("Enter the amount of numbers u want to get from the file: ");
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(file, "%d", &snumber);
        printf("%d\n", snumber);
    }
    fclose(file);
    //7.5
    file = fopen("number.txt", "w");
    printf("Enter ur array u want to put into the file:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d] = ", i);
        scanf_s("%d", &arr[i]);
        fprintf(file, "%d", arr[i]);
        fprintf(file, "%c", ' ');
    }
    fclose(file);
    //7.6
    file = fopen("number.txt", "r");
    printf("Ur array u wanted to get from the file:\n");
    for (int i = 0; i < 10; i++)
    {
        fscanf(file, "%d", &arr[i]);
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    fclose(file);
    //7.7
    file = fopen("number.txt", "w");
    printf("Enter ur matrix u want to put into the file:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("matr[%d][%d] = ", i, j);
            scanf_s("%d", &matr[i][j]);
            fprintf(file, "%d", matr[i][j]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
    fclose(file);
    //7.8
    file = fopen("number.txt", "r");
    printf("Ur matrix u wanted to get from the file:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(file, "%d", &matr[i][j]);
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}