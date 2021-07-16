#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word
{
	char* data;
	int freq;
	Word* next;
	Word* prev;
} word;

typedef struct Dictionary
{
	int size;
	word* head;
	word* tail;
} dict;

dict* create_dict()
{
	dict* Dct = (dict*)malloc(sizeof(dict));
	Dct->size = 0;
	Dct->head = NULL;
	Dct->tail = Dct->head;
	return Dct;
}

void push(dict* Dct, char* data)
{
	word* tmp = (word*)malloc(sizeof(word));
	tmp->freq = 1;
	tmp->data = data;
	tmp->next = Dct->head;
	tmp->prev = NULL;
	if (Dct->head)
		Dct->head->prev = tmp;
	if (Dct->tail == NULL)
		Dct->tail = tmp;
	Dct->head = tmp;
	Dct->size++;
}

void push_back(dict* Dct, char* data)
{
	word* tmp = (word*)malloc(sizeof(word));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = Dct->tail;
	if (Dct->tail == NULL)
	{
		Dct->tail = tmp;
		Dct->head = tmp;
	}
	else
		Dct->tail->next = tmp;
	Dct->tail = tmp;
	Dct->size++;
}

char* pop(dict* Dct)
{
	if (Dct->head == NULL)
	{
		printf("The dictionary is empty!\n");
		return NULL;
	}
	word* tmp = Dct->head;
	char* data = tmp->data;
	Dct->head = tmp->next;
	if (Dct->head)
		Dct->head->prev = NULL;
	Dct->size--;
	free(tmp);
	if (Dct->size == 0)
		Dct->tail = NULL;
	return data;
}

void FillDict(dict* Dct, FILE* file) //заполнение словаря и подсчет частотности слов
{
	const char* delim = " ,.:;!?";
	char data[5000];
	char* data_word;
	int cmp = 0;
	data_word = fgets(data, sizeof(data), file);
	data_word = strtok(data, delim);
	push(Dct, data_word);
	word* tmp;
	while (data_word)
	{
		tmp = Dct->tail;
		data_word = strtok(NULL, delim);
		while (tmp)
		{
			if (!data_word)
				break;
			cmp = strcmp(data_word, tmp->data);
			if (cmp == 0)
			{
				tmp->freq++;
				break;
			}
			tmp = tmp->prev;
		}
		if ((cmp != 0) && (data_word))
		{
			push(Dct, data_word);
		}
	}
	printf("The dictionary has been successfully filled!\n");
}

void swp(dict* Dct, word* tmp) //поменять местами элементы
{
	word *prev = Dct->head, *swp;

	if (tmp != Dct->head)

		while (prev->next != tmp)
			prev = prev->next;

	swp = tmp->next;
	tmp->next = swp->next;
	swp->next = tmp;

	if (tmp == Dct->head)
		Dct->head = swp;
	else
		prev->next = swp;


}
void BubbleSortDict(dict* Dct) //сортировка пузырьком по частоте встречаемости слова
{
	int flag = 1;
	if (!Dct->head)
		return;
	while (flag)
	{
		flag = 0;
		word* tmp = Dct->head;
		while (tmp->next)
			if (tmp->freq < tmp->next->freq)
			{
				swp(Dct, tmp);
				flag = 1;
			}
			else
				tmp = tmp->next;

	}
}

void print_dict(dict* Dct)
{
	if (Dct->head == NULL)
	{
		printf("the dictionary is empty!\n");
		return;
	}
	word* tmp = Dct->head;
	while (tmp)
	{
		printf("%s - %d\n", tmp->data, tmp->freq);
		tmp = tmp->next;
	}
}

void clear_dict(dict* Dct)
{
	while (Dct->head)
	{
		pop(Dct);
	}
	printf("The dictionary has been successfully cleared\n");
}

int main()
{
	dict* Dct = create_dict();
	FILE* file;
	file = fopen("file.txt", "r");
	FillDict(Dct, file);
	fclose(file);
	BubbleSortDict(Dct);
	print_dict(Dct);
	clear_dict(Dct);
	free(Dct);
}