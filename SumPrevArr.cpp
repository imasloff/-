#include <stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        if ((i == 0) || (i == 1))
            scanf_s("%d", &arr[i]);
        else
            arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}
