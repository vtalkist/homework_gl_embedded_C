#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "str_copy.h"
#include "stack.h"
#include "queue.h"
#include "generical_map.h"


#define elements(array) (sizeof(array)/sizeof(array[0]))
void show_menu(void);

main()
{
	while (1) {
		int value = 0;
		show_menu();
		scanf("%d", &value);
		while (getchar() != '\n')
			;
		switch (value)
		{
		case 1:
		{
			printf("Enter line for copying\n");
			char arr[80];
			fgets(arr, sizeof(arr), stdin);
			char *the_pointer = my_strcpy(arr);
			fputs(the_pointer, stdout);
			break;
		}
		case 2:
		{
			printf("Enter stack elements\n");
			int tmp = 0;
			Node *head = NULL;
			while (scanf("%d", &tmp) != 0)
				push(&head, tmp);

			while (getchar() != '\n');
			;
			printf("--------------\n");
			//print_stack(head);
			for (int i = stack_size(head); i > 0; i--)
				printf("%d\n", pop_value(&head));
			break;
		}
		case 3:
		{
			printf("Enter int queue elements\n");
			Queue var;
			init_queue(&var);
			int a = 0;
			while (scanf("%d", &a))
				enqueue(&var, a);
			while (getchar() != '\n')
				;
			printf("--------------------\n");
			while (var.size > 0)
				printf("%d\n", dequeue(&var));
			break;
		}
		case 4:
		{
			unsigned i;
			int src[] = { 0, 1, 2, 3 };
			int dest[elements(src)];
			MapArray(src, dest, func, elements(src));
			for (i = 0; i < elements(src); i++)
				printf("%d\n", dest[i]);
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

void show_menu(void)
{
	printf("\t\t1. Copy string\n\
		2. Stack library\n\
		3. Queue lib\n\
		4. Map func\n\
		0. Exit\n");
}