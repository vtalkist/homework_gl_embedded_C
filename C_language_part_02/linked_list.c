#include "linked_list.h"

void list_init(LinkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void fill_list(LinkedList *list)
{
	printf("Enter int values\n");
	int tmp_data = 0;
	while (scanf("%d", &tmp_data))
	{
		Data *tmp = (Data*)malloc(sizeof(tmp));
		tmp->value = tmp_data;
		list_add(list, tmp);
	}
	while (getchar() != '\n');
		;
}
void list_add(LinkedList *list, void *data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL) {
		list->tail = node;
		node->next = NULL;
		list->head = node;
	}
	else {
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	}
}

void list_remove(LinkedList *list, Node *node)
{
	if (node == list->head) {
		if (list->head->next == NULL) {
			list->head = list->tail = NULL;
		}
		else {
			list->head = list->head->next;
		}
	}
	else {
		Node *tmp = list->head;
		while (tmp->next != node) {
			tmp = tmp->next;
		}
		if (tmp != NULL) {
			tmp->next = node->next;
		}
	}
	free(node);
}

Node* list_contains(LinkedList *list, void *data)
{
	Node *current = list->head;
	while (current != NULL)
	{
		if (compare(current->data, data))
			return current;
		current = current->next;
	}
	return NULL;
}

void list_display(LinkedList* list)
{
	Node *current = list->head;
	while (current != NULL)
	{
		display(current->data);
		current = current->next;
	}
}

void display(Data* data) {
	printf("%d\n", data->value);
}

bool compare(Data* data, Data* data2) {
	return  data->value == data2->value ? true : false;
}