#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "1.4.0_keyword_unsigned.h"

void keyword_unsigned_test(void)
{
	char ch_array[1000];
	int i;
	for(i = 0; i < 1000; i++)
	{
		ch_array[i] = -1 - i;
		//lk_print("cha_array[%d] = 0x%02x.\n", i, ch_array[i]);
	}
	lk_print("strlen(ch_array) = %ld.\n", strlen(ch_array));
	lk_print("ch_array[strlen(ch_array)]= 0x%x.\n", ch_array[strlen(ch_array)]);
}
