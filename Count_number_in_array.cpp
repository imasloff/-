#include <iostream>

int main()
{
    int arr[10];
    int num, cnt = 0;
    printf("Enter an array:\n");
    for (int i = 0; i < 10; i++)
        scanf_s("%d", &arr[i]);
    printf("Enter the number you want to count:\n");
    scanf_s("%d", &num);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == num)
            cnt++;
    }
    if (cnt != 0)
        printf("%d - %d times", num, cnt);
    else 
        printf("There's no such number in your array");
}
