#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

void convert_string(char* str, unsigned long begin, unsigned long end)
{
	unsigned long i;
	char temp;

	_ASSERT(((str == NULL) || (begin < 0) || (end < 0) || (begin > end)));
	//lk_print("begin: %ld, end: %ld.\n", begin, end);
	for(i = begin; i < (begin + end + 1)/2; i++)
	{
		temp = *(str + i);
		*(str + i) =*(str + end - (i - begin));
		*(str + end - (i - begin)) = temp;
	}
}

void convert_string_test(char *str, long num)
{
	_ASSERT((str == NULL));

	//lk_print("string len: %ld, num: %ld.\n", strlen(str), num);
	if(num < 0)
	{
		num = (-num) % strlen(str);
		num = strlen(str) - num;
	}
	else if(num > 0)
	{
		num = num % strlen(str);
	}
	if(num == 0)
	{
		lk_print("str0:%s\n", str);
		return;
	}
	_ASSERT((num < 0));

	//lk_print("string len: %ld, num: %ld.\n", strlen(str), num);
	convert_string(str, 0, strlen(str) - 1);
	lk_print("str1:%s\n", str);

	convert_string(str, 0, strlen(str) - 1 - num);
	lk_print("str2:%s\n", str);

	convert_string(str, strlen(str) - num, strlen(str) - 1);
	lk_print("str3:%s\n", str);
}

