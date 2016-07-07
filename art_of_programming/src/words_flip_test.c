#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"


void words_flip_test(char *str)
{
	unsigned long temp = 0, i = 0;

	lk_print("str0: |%s|\n", str);
	convert_string(str, 0, strlen(str) - 1);
	lk_print("str1: |%s|\n", str);
	while(*(str + i) != '\0')
	{
		if((*(str + i) == ' ') && (*(str + i + 1) != ' '))
			temp = i + 1;
		if((*(str + i) != ' ') && (*(str + i + 1) == ' ') && (temp < (i + 1)))
			convert_string(str, temp, i);
		i++;
		//printf("temp:%ld, i:%ld.\n", temp, i);
	}
	lk_print("str2: |%s|\n", str);
}

