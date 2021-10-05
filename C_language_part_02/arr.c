#include "arr.h"
void input_arr(int **array_ptr, size_t *size)
{
	printf("Enter int arr elements. Any single char for exit\n");
	int tmp = 0;
	while (scanf("%d", &tmp) != 0)
		arr_push(array_ptr, size, tmp);
	while (getchar() != '\n');
		;
}

void arr_push(int **array_ptr, size_t *size, int element)
{
	*(size) = *(size) + 1;
	*array_ptr = (int*)realloc(*array_ptr, *size * sizeof(int));
	*(*array_ptr + *size - 1) = element;
	
}

void arr_print(int** array_ptr, size_t *size)
{
	for(int i = 0; i < *size; i++)
		printf("%d\n", *(*array_ptr+i));
}

unsigned int arr_find_first(int **array_ptr, size_t *size, int element)
{
	for (int i = 0; i < *size; i++)
		if (*(*array_ptr + i) == element)
			return i;
	return -1;
}

void arr_remove(int **array_ptr, size_t *size, int index)
{
	int *new_array_ptr = (int*)malloc(((*size) - 1) * sizeof(int));
	for (int i = 0, a = (*size) - 1; i < index && a >= index; i++, a--)
	{
		new_array_ptr[i] = *(*array_ptr + i);
		new_array_ptr[a - 1] = *(*array_ptr + a);
	}
	free(*array_ptr);
	*array_ptr = new_array_ptr;
	*(size) = *(size) - 1;
}