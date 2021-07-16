#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data = 0;
	node* next;
	node* prev;
};

typedef struct list
{
	int size;
	node* head;
	node* tail;
};

list* create_list()
{
	list* lt = (list*)malloc(sizeof(list));
	lt->size = 0;
	lt->head = NULL;
	lt->tail = lt->head;
	return lt;
}

void push(list* lt, int data)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = lt->head;
	tmp->prev = NULL;
	if (lt->head)
		lt->head->prev = tmp;
	if (lt->tail == NULL)
		lt->tail = tmp;
	lt->head = tmp;
	lt->size++;
}

void push_back(list* lt, int data)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = lt->tail;
	if (lt->tail == NULL)
	{
		lt->tail = tmp;
		lt->head = tmp;
	}
	else
		lt->tail->next = tmp;
	lt->tail = tmp;
	lt->size++;
}

int pop(list* lt)
{
	if (lt->head == NULL)
	{
		printf("the list is empty!\n");
		return NULL;
	}
	node* tmp = lt->head;
	int data = tmp->data;
	lt->head = tmp->next;
	if (lt->head)
		lt->head->prev = NULL;
	lt->size--;
	free(tmp);
	if (lt->size == 0)
		lt->tail = NULL;
	return data;
}

void print_list(list* lt)
{
	if (lt->head == NULL)
	{
		printf("the list is empty!\n");
		return;
	}
	node* tmp = lt->head;
	printf("NULL<->");
	while (tmp)
	{
		printf("[%d]<->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int pop_back(list* lt)
{
	if (lt->tail == NULL)
	{
		printf("the list is empty!\n");
		return NULL;
	}
	node* tmp = lt->tail;
	int data = tmp->data;
	lt->tail = lt->tail->prev;
	if (lt->tail)
		lt->tail->next = NULL;
	if (tmp == lt->head)
		lt->head = NULL;
	lt->size--;
	free(tmp);
	return data;
}

void fill_list(list* lt)
{
	int N = 0;
	int data = 0;
	printf("Enter the number of elements in the list: ");
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		printf("Enter the data of the %d element: ", i);
		scanf_s("%d", &data);
		push(lt, data);
	}
	print_list(lt);
}

void fill_back_list(list* lt)
{
	int N = 0;
	int data = 0;
	printf("Enter the number of elements in the list: ");
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		printf("Enter the data of the %d element: ", i);
		scanf_s("%d", &data);
		push_back(lt, data);
	}
	print_list(lt);
}

void add(list* lt)
{
	int pos;
	int data;
	printf("Enter the position of the element (from the head): ");
	scanf_s("%d", &pos);
	if ((pos > 0) && (pos <= lt->size + 1))
	{
		printf("Enter the data of the element: ");
		scanf_s("%d", &data);
		if (pos == 1)
			push(lt, data);
		else if (pos == lt->size + 1)
			push_back(lt, data);
		else
		{
			node* tmp,* elem;
			tmp = lt->head;
			elem = (node*)malloc(sizeof(node));
			elem->data = data;
			for (int i = 1; i < pos - 1; i++)
				tmp = tmp->next;
			elem->prev = tmp;
			elem->next = tmp->next;
			tmp->next = elem;
		}
		lt->size++;
	}
	else
		printf("There's no such position!\n");
}

void swap(list* lt)
{
	int pos1, pos2;
	printf("Enter the position of the 1st element (from the head): ");
	scanf_s("%d", &pos1);
	printf("Enter the position of the 2nd element (from the head): ");
	scanf_s("%d", &pos2);
	if (pos2 < pos1)
	{
		int temp;
		temp = pos1;
		pos1 = pos2;
		pos2 = temp;
	}
	node* prev1 = NULL, * prev2 = NULL, * node1, * node2;
	node* swp;
	int k = 1;
	if (pos1 == pos2)
	{
		printf("You've entered equal positions!\n");
	}
	node1 = lt->head;
	while (k != pos1)
	{
		node1 = node1->next;
		k++;
	}
	prev1 = node1->prev;
	prev2 = prev1;
	node2 = node1;
	while (k != pos2)
	{
		node2 = node2->next;
		k++;
	}
	prev2 = node2->prev;
	prev2->next = node1;
	swp = node1->next;
	node1->next = node2->next;
	node2->next = swp;

	if (node1->next == NULL)
		lt->tail = node1;
	else if (node2->next == NULL)
		lt->tail = node1;
	if (prev1)
		prev1->next = node2;
	else
		lt->head = node2;
}

void saveToFile(list* lt, FILE* file)
{
	if (lt->head == NULL)
	{
		printf("the list is empty!\n");
		return;
	}
	node* tmp = lt->head;
	while (tmp)
	{
		fprintf(file, "%d", tmp->data);
		if (tmp->next)
			fprintf(file, "%c", '\n');
		tmp = tmp->next;
	}
	printf("the list has been successfully saved!\n");
	fclose(file);
}

void readFromFile(list* lt, FILE* file)
{
	int data;
	while (!feof(file))
	{
		fscanf_s(file, "%d", &data);
		push(lt, data);
	}
	printf("the list has been successfully read!\n");
	fclose(file);
}

void clear_list(list* lt)
{
	while (lt->head)
	{
		pop(lt);
	}
	printf("the list has been successfully cleared\n");
}

int main()
{
	//тест
	list* lt = create_list();
	push(lt, 1);
	print_list(lt);
	push(lt, 2);
	print_list(lt);
	pop(lt);
	print_list(lt);
	push_back(lt, 5);
	print_list(lt);
	pop_back(lt);
	print_list(lt);
	fill_list(lt);
	fill_back_list(lt);
	add(lt);
	print_list(lt);
	add(lt);
	print_list(lt);
	add(lt);
	print_list(lt);
	swap(lt);
	print_list(lt);
	FILE* file = fopen("list.txt", "a");
	fill_list(lt);
	print_list(lt);
	saveToFile(lt, file);
	clear_list(lt);
	print_list(lt);
	/*FILE* file = fopen("list.txt", "r");
	readFromFile(lt, file);
	print_list(lt);
	clear_list(lt);
	print_list(lt);*/
	free(lt);
}
