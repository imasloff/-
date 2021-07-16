#include "stdio.h"

int main()
{
    const int N = 10;
    int arr[N], tmp;
    printf("Enter your array:\n");
    for (int i = 0; i < N; i++)
        scanf_s("%d", &arr[i]);
    for (int i = 0; i < N - i - 1; i++)
    {
        tmp = arr[i];
        arr[i] = arr[N - i - 1];
        arr[N - i - 1] = tmp;
    }
    printf("Your reversed array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}