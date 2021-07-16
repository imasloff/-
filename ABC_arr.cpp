#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10], B[10], C[10], cnt = 0;
    
    for (int i = 0; i < 10; i++)
        scanf_s("%d", &A[i]);
    for (int i = 0; i < 10; i++)
        scanf_s("%d", &B[i]);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (A[i] == B[j])
            {
                C[cnt] = A[i];
                cnt++;
                break;
            }
        }
    }

    for (int i = 0; i < cnt; i++)
        printf("%d ", C[i]);
}
