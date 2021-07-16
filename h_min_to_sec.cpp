#include "stdio.h"
#include <clocale>

int main()
{
    int sec, min, hours;

    printf("Enter sec: ");
    scanf_s("%d", &sec);

    hours = sec / 3600;
    min = (sec % 3600) / 60;
    sec = (sec % 3600) % 60;

    printf("%dh %dm %ds\n", hours, min, sec);
}
