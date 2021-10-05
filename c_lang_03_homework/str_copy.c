#include "str_copy.h"


char *my_strcpy(const char *src)
{
	const char *sc;
	char *pointer;
	char *new_src = NULL;
	for (sc = src; *sc != '\0'; ++sc)
		;
	int a = sc - src;
	new_src = (char*)calloc(sc - src + 1, sizeof(char));
	pointer = new_src;
	for (sc = src; (*pointer++ = *sc++) != '\0'; )
		;
	return new_src;
}
