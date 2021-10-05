#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
#include "linked_list.h"
#include "arr.h"

void menu_text(void);

int main(void)
{
	int case_value = 0;
	while (1)
	{
		menu_text();
		scanf("%d", &case_value);
		switch (case_value)
		{
			case 1:
			{
				size_t size = 0;
				int *p = input_array(&size);
				printf("The biggest element is: %d\n",
				biggest(p, size));
				//print_arr(p, &size);
				break;
			}
			case 2:
			{
				LinkedList linked_list;
				int a = 0;
				list_init(&linked_list);
				fill_list(&linked_list);
				printf("-------------------------------\n");
				printf("Enter el. for removing by value\n");
				scanf("%d", &a);
				Node *tmp = list_contains(&linked_list, &a);
				list_remove(&linked_list, tmp);
				printf("-------------------------------\n");
				list_display(&linked_list, (DISPLAY)display);
				break;
			}
			case 3:
			{
				int *arr = NULL;
				int tmp = 0;
				size_t arr_size = 0;
				input_arr(&arr, &arr_size);
				printf("-------------------------------\n");
				arr_print(&arr, &arr_size);
				printf("Enter index of el for rem\n");
				scanf("%d", &tmp);
				arr_remove(&arr, &arr_size, tmp);
				printf("-------------------------------\n");
				arr_print(&arr, &arr_size);
				break;
			}
			case 0:
				exit(0);
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void menu_text(void)
{
	printf("\t\t1. Find biggest el in array\n\
		2. Linked list lib\n\
		3. Integer arr lib\n\
		0. Exit\n");
}

