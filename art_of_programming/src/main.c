#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

int main(void)
{
	//char str[100] = "abcdefghijklmnopqrstuvwxyz";
	//char str[100] = " I am    a       student.  ";
	int num[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//char *p_str = str;

	//convert_string_test(str, 0);
	//convert_string_use_listnode_test(str, 0);
	//words_flip_test(str);
	flip_number_use_listnode_test(num, 10, 2);
	//lk_print("str:%s.\n", str);

	return 0;
}
