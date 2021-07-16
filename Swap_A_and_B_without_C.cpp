#include "stdio.h"

int main()
{
    int a, b;
    printf("Enter a: ");
    scanf_s("%d", &a);
    printf("Enter b: ");
    scanf_s("%d", &b);

    a += b;
    b = a - b;
    a = a - b;

    printf("a = %d, b = %d", a, b);
}


