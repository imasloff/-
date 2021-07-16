#include "stdio.h"

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf_s("%d", &a[i]);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
}
