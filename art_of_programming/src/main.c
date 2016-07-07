#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

int main(void)
{
	//char str[100] = "abcdefghijklmnopqrstuvwxyz";
	char str[100] = " I am    a       student.  ";
	//char *p_str = str;

	//convert_string_test(str, 0);
	//convert_string_use_listnode_test(str, 0);
	words_flip_test(str);
	//lk_print("str:%s.\n", str);

	return 0;
}
