#include <stdio.h>
#include <string.h>
#include "lk_debug.h"

int judge_substring_contain(char *str_sub, char *str)
{
	int hash_table = 0;

	if(str_sub == NULL || str == NULL)
	{
		lk_print("*str_sub or *str is null.\n");
		return -1;
	}
	while(*(str) != '\0')
	{
		if(*str < 'a' || *str >'z')
			return -1;
		hash_table |= (1 << (*str - 'a'));
		str++;
	}
	lk_print("hast_table: 0x%x.\n", hash_table);

	while(*str_sub != '\0')
	{
		if(*str_sub < 'a' || *str_sub >'z')
			return -1;
		if(0 != (hash_table & (1 << (*str_sub - 'a'))))
			str_sub++;
		else
			return 0;
	}
	return 1;
}
