#include <stdio.h>
#include <stdlib.h>

#define N 10

void getarr(int* arr)
{
    printf("Enter the array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf_s("%d", &arr[i]);
    }
}

void putarr(int* arr)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
}

void bubbleSort(int* arr)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void insertSort(int* arr)
{
    for (int i = 1; i < N; i++) 
    {
        for (int j = i; ((j > 0) && (arr[j - 1] > arr[j])); j--)
        {
            int tmp = arr[j-1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void selectSort(int* arr)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main()
{
    int arr[N];
    getarr(arr);
    //bubbleSort(arr);
    //insertSort(arr);
    selectSort(arr);
    putarr(arr);
}
