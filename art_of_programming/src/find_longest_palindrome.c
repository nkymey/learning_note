#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lk_debug.h"

long find_longest_palindrome(const char *str, long length)
{
	long i = 0, j = 1, max = 1;
	char *str_insert = NULL;


	str_insert = (char *)malloc(2 * length * sizeof(char) + 1);

	if(str == NULL || length < 1 || str_insert == NULL)
		return 0;

	while(i < (2 * length + 1))
	{
		if(i % 2 == 0)
			*(str_insert + i) = '#';
		else
		{
			*(str_insert + i) = *(str + (i - 1)/2);
		}
		i++;
	}
	*(str_insert + i) = '\0';
#if 0
	i = 0;
	while(i < (2 * length + 1))
	{
		printf("%c", *(str_insert + i));
		i++;
	}
	printf("\n");
#endif

	i = 1;
	while(i < (2 * length + 1))
	{
		j = 1;
		while(1)
		{
			if(*(str_insert + i - j) == *(str_insert + i + j) && (i >= j))
				j++;
			else
				break;
		}
		if(j/2 > max)
		{
			lk_print("i: %ld, j: %ld.\n", (i - 1)/2, j/2);
			max = j/2;
		}
		i++;
	}
	free(str_insert);

	return max;
}
