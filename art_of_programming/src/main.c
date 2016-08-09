#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

int main(void)
{
	char str[100] = "abcdefghijklmnopqrstuvwxyz";
	char str_word[100] = " I am    a       student.  ";
	char substr[20] = "helloworld";
	int num[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char str_pali[100] = "sdfeefdsaaasdfghjkjhgfdsaqwett";
	//char *p_str = str;

	convert_string_test(str, 0);
	convert_string_use_listnode_test(str, 0);
	words_flip_test(str_word);
	flip_number_use_listnode_test(num, 10, 2);
	lk_print("str:%s.\n", str);
	if(1 == judge_substring_contain(substr, str))
		lk_print("str contain substr.\n");
	else
		lk_print("str don't  contain substr.\n");
	find_longest_palindrome(str_pali, strlen(str_pali));

	return 0;
}
