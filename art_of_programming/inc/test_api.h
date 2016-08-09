#ifndef __TEST_API_H__
#define __TEST_API_H__

void convert_string(char* str, unsigned long begin, unsigned long end);
void convert_string_test(char *str, long num);
void convert_string_use_listnode_test(char *str, long num);
void words_flip_test(char *str);
void flip_number_use_listnode_test(int *array_num, long len, long num);
int judge_substring_contain(char *str_sub, char *str);
long find_longest_palindrome(const char *str, long length);

#endif
