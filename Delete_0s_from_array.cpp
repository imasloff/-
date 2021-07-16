#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int n, count = 0;
    printf("Enter the size of the array: ");
    scanf_s("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter your array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf_s("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j < n; j++)
                arr[j] = arr[j + 1];
            count++;
        }
    }
    int m = n - count;
    arr = (int*)realloc(arr, m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}
