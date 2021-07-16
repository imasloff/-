#include <stdio.h>

int main()
{
	int matr[4][4], tmp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("matr[%d][%d] = ", i, j);
			scanf_s("%d", &matr[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j >= i)
			{
				tmp = matr[i][j];
				matr[i][j] = matr[j][i];
				matr[j][i] = tmp;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
}
