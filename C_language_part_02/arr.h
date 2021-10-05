#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#include <stdlib.h>
#include <stdio.h>

void arr_push(int **, size_t *, int);
void arr_print(int **, size_t *);
unsigned int arr_find_first(int **, size_t *, int);
void arr_remove(int **, size_t *, int);
void arr_remove(int **, size_t *, int );
void input_arr(int **, size_t *);