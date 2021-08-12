#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PI       3.14159265358979323846   // pi

uint16_t swap_uint16(uint16_t val);
uint32_t swap_uint32(uint32_t val);
uint64_t swap_uint64(uint64_t val);

uint16_t decode_rgb_888_565(uint8_t red,
	uint8_t green,
	uint8_t blue);

void calc_rectangle_perimeter_and_area_in_inches(struct rectangle *rectangle);
double meters_to_inches(double value);
void calc_circle_perimeter_and_area(struct circle * circle);

int *are_divisible_in_range(int number,
	int range_begin,
	int range_end,
	size_t *arr_size);
void menu_text(void);

struct rectangle {
	double height_in_meters;
	double width_in_meters;
	double perimeter_in_inches;
	double area_in_inches;
};

struct circle {
	double radius;
	double perimeter;
	double area;
};

int main(void)
{
	while (1) {
		int num = 0;
		menu_text();
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			uint16_t little16 = 0;
			printf("Enter uint16 hex value as: #### ");
			scanf("%hx", &little16);
			printf("Converted uint16 = %x\n",
				swap_uint16(little16));
			break;
		}
		case 2:
		{
			uint32_t little32 = 0;
			uint16_t little1 = 0;
			uint16_t little2 = 0;
			printf("Enter uint32 hex value as: #### #### ");
			scanf("%hx %hx", &little1, &little2);
			little32 = little1 << 16;
			little32 = little32 | little2;
			printf("Converted uint32 = %lx\n", little32);
			printf("Converted uint32 = %lx\n",
				swap_uint32(little32));
			break;
		}
		case 3:
		{
			uint64_t little64 = 0;
			uint16_t little1 = 0;
			uint16_t little2 = 0;
			uint16_t little3 = 0;
			uint16_t little4 = 0;
			printf("Enter uint32 hex value as: #### #### #### #### ");
			scanf("%hx %hx %hx %hx",
				&little1, &little2, &little3, &little4);
			little64 = (little64 = little1) << 16;
			little64 = (little64 | little2) << 16;
			little64 = (little64 | little3) << 16;
			little64 = (little64 | little4);
			printf("Converted uint64 = %llx\n",
				swap_uint64(little64));
			break;
		}
		case 4:
		{
			char r = 0, g = 0, b = 0;
			printf("Enter RGB888 hex values as: ## ## ## ");
			scanf("%x %x %x", &r, &g, &b);
			printf("rgb = %x\n", decode_rgb_888_565(r, g, b));
			break;
		}
		case 5:
		{
			struct rectangle rectangle;
			printf("enter rectangle height and width in meters\n");
			scanf("%lf %lf", &rectangle.height_in_meters,
				&rectangle.width_in_meters);
			calc_rectangle_perimeter_and_area_in_inches(&rectangle);
			printf("rectangle perimeter in inches = %lf\n\
rectangle area in inches = %lf\n",
rectangle.perimeter_in_inches,
rectangle.area_in_inches);
			break;
		}
		case 6:
		{
			struct circle circle;
			double tmp = 0;
			printf("Enter circle radius value ");
			scanf("%lf", &tmp);
			circle.radius = tmp;
			calc_circle_perimeter_and_area(&circle);
			printf("circle perimeter = %lf\ncircle area = %lf\n",
				circle.perimeter, circle.area);
			break;
		}
		case 7:
		{
			int a = 0;
			printf("Enter number for factorial value computation ");
			scanf("%d", &a);
			printf("factorial value = %d\n", factorial(a));
			break;
		}
		case 8:
		{
			int number = 0, range_begin = 0, range_end = 0;
			printf("Enter number, range begin, range end ");
			scanf("%d %d %d",
				&number,
				&range_begin,
				&range_end);
			size_t arr_size = 0;
			int *p = are_divisible_in_range(number,
				range_begin,
				range_end,
				&arr_size);
			for (int i = 0; i < arr_size; i++)
				printf("%d\n", p[i]);
			free(p);
			break;
		}
		case 0:
			printf("Exit");
			exit(0);
		}
	}
	system("pause");
	return 0;
}

uint16_t swap_uint16(uint16_t val)
{
	return (val << 8) | (val >> 8);
}

uint32_t swap_uint32(uint32_t val)
{
	return (val << 8 & 0x00FF0000) | (val >> 8 & 0x0000FF00) |
		(val >> 24) | (val << 24);
}

uint64_t swap_uint64(uint64_t val)
{
	return (val << 8 & 0xFF00000000) | (val >> 8 & 0xFF000000) |
		(val << 24 & 0xFF0000000000) | (val >> 24 & 0xFF0000) |
		(val << 40 & 0xFF000000000000) | (val >> 40 & 0xFF00) |
		(val << 56 & 0xFF00000000000000) | (val >> 56 & 0xFF);
}

/*
* This function decodes RGB888 to RGB565
*/

uint16_t decode_rgb_888_565(uint8_t red,
	uint8_t green,
	uint8_t blue)
{
	return ((red & 0xF8) << 8) |
		((green & 0xFC) << 3) |
		(blue >> 3);
}

/*
* This function calculates the perimeter and
* area of a rectangle by width and heigth of rectangle in meters
*/

void calc_rectangle_perimeter_and_area_in_inches(struct rectangle *rectangle)
{
	rectangle->perimeter_in_inches =
		meters_to_inches(2 * (rectangle->width_in_meters
			+ rectangle->height_in_meters));

	rectangle->area_in_inches =
		meters_to_inches(rectangle->height_in_meters
			* rectangle->width_in_meters);
}

/*
* This feature converts meters to inches
*/

double meters_to_inches(double value)
{
	return value / 0.0254;
}

/*
* This function calculates the perimeter and
* area of a circle by radius
*/

void calc_circle_perimeter_and_area(struct circle * circle)
{
	circle->perimeter = 2 * PI * circle->radius;
	circle->area = PI * (circle->radius * circle->radius);
}

/*
* This function calculates the factorial of a given number
*/

int factorial(int n)
{
	return n == 0 ? 1 : n < 0 ? -1 : factorial(n - 1) * n;
}

/*
* This function returns an array of elements
* in a range divisible by a given number
*/

int *are_divisible_in_range(int number,
	int range_begin,
	int range_end,
	size_t *arr_size)
{
	int *arr = NULL;
	int a = 0;
	arr = (int*)malloc(range_end * sizeof(int));
	if (!arr)
	{
		printf("Can't allocate memory inside\
			\"are_divisible_in_range\" function");
		exit(0);
	}
	for (int i = range_begin; i <= range_end; i++)
		if (i % number == 0)
			arr[a++] = i;
	arr = (int*)realloc(arr, a * sizeof(int));
	if (!arr)
	{
		printf("Can't reallocate memory inside\
			\"are_divisible_in_range\" function");
		exit(0);
	}
	*arr_size = a;
	return arr;
}

/*
* This function displays menu items on the screen
*/

void menu_text(void)
{
	printf("\t\t1 - swap uint16_t\n\
		2 - swap uint32_t\n\
		3 - swap uint64_t\n\
		4 - RGB888 to RGB565\n\
		5 - rectangle perimeter and area\n\
		6 - circle perimeter and area\n\
		7 - factorial value\n\
		8 - in range divisible by num\n\
		0 - Exit\n");
}