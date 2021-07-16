#include "stdio.h"

void printFor(int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
}

void printForEv(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if ((i % 2) == 0)
			printf("%d ", i);
	}
}

int sumFor(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += i;
	return res;
}

void divFor(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if ((n % i) == 0)
			printf("%d ", i);
	}
}

void ifPrime(int n)
{
	int tmp = 0;
	for (int i = 2; i < n; i++)
	{
		if ((n % i) == 0)
			tmp++;
	}
	if ((n > 0) && (tmp == 0))
		printf("Prime\n");
	else
		printf("Not prime\n");
}

int degFor(int n, int deg)
{
	int tmp = 1;
	for (int i = 1; i <= deg; i++)
		tmp *= n;
	return tmp;
}


int main() 
{
	int n, deg;
	printf("Enter N: ");
	scanf_s("%d", &n);

	printFor(n);

	printf("\n");

	printForEv(n);

	printf("\n");

	printf("SUM = %d\n", sumFor(n));

	divFor(n);

	printf("\n");

	ifPrime(n);

	printf("Enter degree: ");
	scanf_s("%d", &deg);
	printf("%d^%d = %d\n", n, deg, degFor(n, deg));
}
