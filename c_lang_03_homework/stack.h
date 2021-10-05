#pragma once
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

void push(Node **head, int value);
Node *pop_node(Node **head);
int pop_value(Node **head);
void print_stack(const Node *head);
size_t stack_size(const Node *head);