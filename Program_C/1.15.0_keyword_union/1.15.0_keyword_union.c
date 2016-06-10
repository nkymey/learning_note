#include <stdio.h>
#include "lk_debug.h"
#include "1.15.0_keyword_union.h"

int check_system_endian(void)
{
	union check
	{
		int i;
		char ch;
	} c;

	c.i = 1;
	return (c.ch == 1);
}

void keyword_union_test(void)
{
	int endian = 0;
	endian = check_system_endian();
	if(endian)
	{
		lk_print("Little Endian.\n");
	}
	else
	{
		lk_print("Big Endian.\n");
	}
}
