#include "functions.h"

int *input_array(size_t *size)
{
	int *arr = NULL, tmp = 0;
	printf("Please, input array.\
\n\t***Type any char for input interruption***\n");
	while(scanf("%d", &tmp))
	{
		arr = (int *)realloc(arr, ++(*size) * sizeof(int));
		*(arr + *size - 1) = tmp;
	}
	while (getchar() != '\n');
		;
	return arr;
}

int biggest(int *arr, int count)
{
	int bigest = *arr;
	for (int i = 0; i < count; i++)
		if (bigest < *(arr + i))
			bigest = *(arr + i);

	return bigest;
}

void print_arr(int *arr, size_t *size)
{
	for (int i = 0; i < *size; i++)
		printf("%d\n", *(arr + i));
}