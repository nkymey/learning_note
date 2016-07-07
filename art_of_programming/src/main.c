#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

int main(void)
{
	char str[100] = "abcdefghijklmnopqrstuvwxyz";
	//char *p_str = str;

	convert_string_test(str, -2300000000L);
	lk_print("str:%s.\n", str);

	return 0;
}
