#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _data {
	int value;
} Data;

typedef struct _node {
	void *data;
	struct _node *next;
} Node;

typedef struct LinkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

void list_init(LinkedList*);
void fill_list(LinkedList*);
void list_add(LinkedList*, void*);
void display(Data*);
bool compare(Data* , Data*);
Node* list_contains(LinkedList *list, void *data);
void list_remove(LinkedList *list, Node *node);

typedef void(*DISPLAY)(void*);