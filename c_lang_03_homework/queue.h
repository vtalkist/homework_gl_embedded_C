#include <stdlib.h>
//#include <string.h>

typedef struct Queue {
	int size;
	int* arr;
} Queue;

void init_queue(Queue *head);
void enqueue(Queue* queue, int item);
int dequeue(Queue *head);
void print_enqueue(Queue* head);