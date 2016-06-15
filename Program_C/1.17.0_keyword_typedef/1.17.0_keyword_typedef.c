#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "1.17.0_keyword_typedef.h"

typedef char* pchar;
#define	PCHAR char*

typedef char a[10];

static void typedef_1_17_4_test(void)
{
//	a[10] a[10];	/* error. */
	/* put variable into typedef */
	a b0 = "I'm b0."; /* b0 replace a: char b0[10]. */
	a b1[10];
	a* b2;
	a* b3[10];
	int a = 9;

	/* Identify what the variable is. */
	printf("b0: %ld\n", sizeof(b0));
	printf("b1: %ld\n", sizeof(b1));
	printf("b2: %ld\n", sizeof(b2));
	printf("b3: %ld\n", sizeof(b3));
	printf("a: %d\n", a);
}

void keyword_typedef_test(void)
{
	pchar p1, p2;
	char str[100];
	PCHAR p3, p4 = 'A';

	p1 = "hello ";
	p2 = "world";
	p3 = "!";
	strcpy(str, p1);
	strcpy(str + strlen(str), p2);
	strcpy(str + strlen(str), p3);
	strcpy(str + strlen(str), "\nI'm a string!");
	puts(str);
	printf("%c\n", p4);
	typedef_1_17_4_test();
}
