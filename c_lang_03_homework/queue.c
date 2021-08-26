#include "queue.h"

void init_queue(Queue *head)
{
	head->arr = NULL;
	head->size = 0;
}

void enqueue(Queue* head, int item)
{
	int *p = NULL;
	if (head->size == 0)
	{
		head->arr = malloc(sizeof(head->arr));
		head->arr[0] = item;
		head->size = head->size + 1;
	}
	else {
		p = malloc(sizeof(head->arr) * (head->size + 1));
		//memcpy(p+1, head->arr, sizeof(head->arr[0]) * head->size);
		for (int i = 0; i < head->size; i++)
			*(p + i + 1) = head->arr[i];
		*(p + 0) = item;
		head->size = head->size + 1;
		free(head->arr);
		head->arr = p;
	}
}

int dequeue(Queue *head)
{
	int val = head->arr[head->size - 1];
	head->arr = realloc(head->arr,
			sizeof(head->arr[0]) * (head->size - 1));
	head->size = head->size - 1;
	return val;
}

void print_enqueue(Queue* head)
{
	for (int i = 0; i < head->size; i++)
		printf("queue #%d -> %d\n", i, head->arr[i]);
}