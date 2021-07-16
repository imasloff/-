#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Student
{
    char name[21];
    char otchestvo[21];
    char surname[21];
    char birthday[11];
    char faculty[11];
    int group;
    int course;
};

int number = 0;

void menu();
void add(Student*);
void del(Student*);
void load(char*, char, Student*);
void save(char*, char, Student*);
int search(char*, Student*);
void sort(Student*);
void edit(Student*);
void printdata(Student*);

int main()
{
    int ch;
    char fname[11], tmp[21], mode = ' ';
    Student ST[100];
    do
    {
        menu();
        scanf_s("%d", &ch);
        getchar();
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            load(fname, mode, ST);
            break;
        case 2:
            add(ST);
            break;
        case 3:
            del(ST);
            break;
        case 4:
            save(fname, mode, ST);
            break;
        case 5:
            printf("Enter the surname of the student you want to search for: ");
            scanf_s("%s", tmp, 21);
            printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[search(tmp, ST)].surname, ST[search(tmp, ST)].name, ST[search(tmp, ST)].otchestvo, ST[search(tmp, ST)].birthday, ST[search(tmp, ST)].faculty, ST[search(tmp, ST)].course, ST[search(tmp, ST)].group);
            break;
        case 6:
            sort(ST);
            break;
        case 7:
            edit(ST);
            break;
        case 8:
            printdata(ST);
            break;
        default:
            printf("error\n");
            break;
        }
    } while (ch != 0);
}

void menu()
{
    printf("MENU:\n'1' - load (file < 100 people)\n'2' - add\n'3' - delete\n'4' - save\n'5' - search\n'6' - sort\n'7' - edit\n'8' - print database\n'0' - exit\n~ ");
}
void add(Student* ST)
{
    int count;
    printf("Enter the number of students you want to add: ");
    scanf_s("%d", &count);
    for (int i = number; i < (number + count); i++)
    {
        printf("Enter the surname: ");
        scanf_s("%s", ST[i].surname, 21);
        printf("Enter the name: ");
        scanf_s("%s", ST[i].name, 21);
        printf("Enter the otchestvo: ");
        scanf_s("%s", ST[i].otchestvo, 21);
        printf("Enter the birthday: ");
        scanf_s("%s", ST[i].birthday, 11);
        printf("Enter the faculty: ");
        scanf_s("%s", ST[i].faculty, 11);
        printf("Enter the course: ");
        scanf_s("%d", &ST[i].course);
        printf("Enter the group: ");
        scanf_s("%d", &ST[i].group);
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[i].surname, ST[i].name, ST[i].otchestvo, ST[i].birthday, ST[i].faculty, ST[i].course, ST[i].group);
    }
    number += count;
}
void del(Student* ST)
{
    Student TMP;
    char tmp[21];
    printf("Enter the surname of the student you want to delete: ");
    scanf_s("%s", tmp, 21);
    for (int i = search(tmp, ST); i < number; i++)
        ST[i] = ST[i + 1];
    number--;
}
void load(char* fname, char mode, Student* ST)
{
    FILE* F;
    printf("Press 'a' to create new base or 'r' to load an existing base: ");
    scanf_s("%c", &mode, 1);
    printf("Enter the file name (with '.txt'): ");
    scanf_s("%s", fname, 10);
    fopen_s(&F, fname, &mode);
    while (!feof(F))
    {
        fscanf(F, "%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[number].surname, ST[number].name, ST[number].otchestvo, ST[number].birthday, ST[number].faculty, &ST[number].course, &ST[number].group);
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[number].surname, ST[number].name, ST[number].otchestvo, ST[number].birthday, ST[number].faculty, ST[number].course, ST[number].group);
        number++;
    }
    fclose(F);
}
void save(char* fname, char mode, Student* ST)
{
    FILE* F;
    printf("Enter the file name (with '.txt'): ");
    scanf_s("%s", fname, 10);
    mode = 'w';
    fopen_s(&F, fname, &mode);
    for (int i = 0; i < number; i++)
        fprintf(F,"%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[i].surname, ST[i].name, ST[i].otchestvo, ST[i].birthday, ST[i].faculty, ST[i].course, ST[i].group);
    fclose(F);
}
int search(char* tmp, Student* ST)
{
    for (int i = 0; i < number; i++)
    {
        if (strcmp(tmp, ST[i].surname) == 0)
            return i;
    }
}
void sort(Student* ST)
{
    Student TMP;
    for (int i = 0; i < number -1; i++)
        for (int j = 0; j < number - i - 1; j++)
            if (strcmp(ST[j].surname, ST[j + 1].surname) > 0) 
            {
                TMP = ST[j];
                ST[j] = ST[j + 1];
                ST[j + 1] = TMP;
            }
}
void edit(Student* ST)
{
    char tmp[21], item;
    printf("Enter the surname of the student you want to edit: ");
    scanf_s("%s", tmp, 21);
    printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[search(tmp, ST)].surname, ST[search(tmp, ST)].name, ST[search(tmp, ST)].otchestvo, ST[search(tmp, ST)].birthday, ST[search(tmp, ST)].faculty, ST[search(tmp, ST)].course, ST[search(tmp, ST)].group);
    printf("Choose the item you want to edit:\n1 - surname\n2 - name\n3 - otchestvo\n4 - birthday\n5 - faculty\n6 - course\n7 - group\n");
    getchar();
    item = getchar();
    switch (item)
    {
    case '1': 
        printf("Enter a new surname: "); 
        scanf_s("%s", ST[search(tmp, ST)].surname, 21); 
        break;
    case '2': 
        printf("Enter a new name: "); 
        scanf_s("%s", ST[search(tmp, ST)].name, 21); 
        break;
    case '3': 
        printf("Enter a new otchestvo: "); 
        scanf_s("%s", ST[search(tmp, ST)].otchestvo, 21); 
        break;
    case '4': 
        printf("Enter a new birthday: "); 
        scanf_s("%s", ST[search(tmp, ST)].birthday, 21); 
        break;
    case '5': 
        printf("Enter a new faculty: "); 
        scanf_s("%s", ST[search(tmp, ST)].faculty, 21); 
        break;
    case '6': 
        printf("Enter a new course: "); 
        scanf_s("%d", &ST[search(tmp, ST)].course); 
        break;
    case '7': 
        printf("Enter a new group: "); 
        scanf_s("%d", &ST[search(tmp, ST)].group); 
        break;
    default: 
        printf("Invalid item"); 
        break;
    }
}
void printdata(Student* ST)
{
    for (int i = 0; i < number; i++)
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", ST[i].surname, ST[i].name, ST[i].otchestvo, ST[i].birthday, ST[i].faculty, ST[i].course, ST[i].group);
}