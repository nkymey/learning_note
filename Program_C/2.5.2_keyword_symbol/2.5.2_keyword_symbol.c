#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "2.5.2_keyword_symbol.h"

void keyword_symbol_test(void)
{
	int i = 3, j, k;
	lk_print("(0x1<<2+3) = %d.\n", (0x1<<2+3));
	lk_print("i = 3, (++i) + (++i) + (++i) = %d.\n", (++i) + (++i) + (++i));
	lk_print("i = %d.\n", i);
	j = (i++, i++, i++);
	lk_print("j = (i++, i++, i++) = %d.\n", j);
	lk_print("i = %d.\n", i);
	j = (++i, i++, i+10);
	lk_print("j = (++i, i++, i+10) = %d.\n", j);
	lk_print("i = %d.\n", i);
	k = (i+++i+++i++);
	lk_print("k= (i+++i+++i++) = %d.\n", k);
	lk_print("i = %d.\n", i);
	k = (++i+(++i)+(++i));
	lk_print("k= (++i+++i+++i) = %d.\n", k);
	k = ((i++)+(i++)+(i++));
	lk_print("k= ((i++)+(i++)+(i++)) = %d.\n", k);
	lk_print("i = %d.\n", i);
	k = (++i)+(++i)+(++i);
	lk_print("k= (++i)+(++i)+(++i) = %d.\n", k);
	lk_print("i= %d, j = %d.\n", i, j);
	lk_print("i+++j = %d.\n", i+++j);
//	lk_print("i= %d, j = %d.\n", i, j);
//	lk_print("i+++++j = %d.\n", i+++++j);
	/* 2.8 */
	lk_print("3/-2 = %d, 3%%(-2) = %d, (-3)/2 = %d, (-3)%%2 = %d.\n", 3/(-2), 3%(-2), (-3)/2, (-3)%2);
	i = 8, j = 10;
	lk_print("i:%d, j:%d, i++:%d, ++j:%d.\n", i, j, i++, ++j);
}
