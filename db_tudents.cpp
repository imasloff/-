#include <stdio.h>
#include <string.h>

#define LEN 20

typedef struct Student
{
	char name[LEN];
	char surname[LEN];
	int score;
};

int n;

Student* fillBase()
{
	printf("Enter the number of students: ");
	scanf_s("%d", &n);
	getchar();
	Student* Base = new Student[n];
	for (int i = 0; i < n; i++)
	{
		printf("Enter the name of the student: ");
		scanf_s("%s", Base[i].name, LEN);
		getchar();
		printf("Enter the surname of the student: ");
		scanf_s("%s", Base[i].surname, LEN);
		printf("Enter the score of the student: ");
		scanf_s("%d", &Base[i].score);
	}
	return Base;
}

void printBase(Student* Base)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%s\t%d\n", i + 1, Base[i].name, Base[i].surname, Base[i].score);
	}
}

int average(Student* Base)
{
	int count = 0;
	int sum = 0;
	while (count < n)
	{
		sum += Base[count].score;
		count++;
	}
	return sum / count;
}

int main()
{
	Student* Base = fillBase();
	printBase(Base);
	printf("Srudents' average score is %d", average(Base));
	delete[] Base;
}