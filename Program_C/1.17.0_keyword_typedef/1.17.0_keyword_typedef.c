#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "1.17.0_keyword_typedef.h"

typedef char* pchar;
#define	PCHAR char*

void keyword_typedef_test(void)
{
	pchar p1, p2;
	char str[100];
	PCHAR p3, p4 = 'A';

	p1 = "hello ";
	p2 = "world";
	p3 = "!";
	strcpy(str, p1);
	strcpy(str + strlen(p1), p2);
	strcpy(str + strlen(p1) +strlen(p2), p3);
	puts(str);
	printf("%c\n", p4);
}
