#include "stack.h"

void push(Node **head, int value)
{
	Node *tmp = malloc(sizeof(Node));
	if (tmp == NULL)
		exit(0);
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
}

Node *pop_node(Node **head)
{
	Node *out;
	if ((*head) == NULL)
		exit(0);
	out = *head;
	*head = (*head)->next;
	return out;
}

int pop_value(Node **head)
{
	Node *out;
	int value;
	if (*head == NULL)
		exit(0);
	out = *head;
	*head = (*head)->next;
	value = out->value;
	free(out);
	return value;
}

void print_stack(const Node *head)
{
	for (; head; head = head->next)
		printf("%d\n", head->value);
}

size_t stack_size(const Node *head)
{
	size_t size = 0;
	for (; head; size++, head = head->next)
		/* nothing */;
	return size;
}