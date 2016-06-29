#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "4.1.3_cpointer.h"

static void TwoD_array_test(void)
{
	int array[5][5] = {(1, 2), (3, 4), (5, 6)};
	int *p;
	int (*ptr)[4];
	int array2[5][5] = {
		1, 2, 3, 4, 5,
		2, 3, 4, 5, 6,
		3, 4, 5, 6, 7,
		4, 5, 6, 7, 8,
		5, 6, 7, 8, 9,
	};
//	int i, j;
	p = array[0];
	lk_print("*p = %d, *(p+1) = %d.\n", *p, *(p+1));
	ptr = array2;
//	for(i = 0; i < 5; i++)
//		for(j = 0; j < 5; j++)
//			printf("array2[%d][%d] = %d.\n",i, j, array2[i][j]);
//	printf("\n");
	lk_print("ptr[4][1]:%d, array[4][1]:%d.\n", ptr[4][1], array2[4][1]);
	lk_print("&ptr[4][1]:%p, &array[4][1]:%p.\n", &ptr[4][1], &array2[4][1]);
}

void cpointer_test(void)
{
	int i = 0x101;
	int *p = &i;
	char *p1 = NULL;
	/* use char, unsigned int test again. */
	int array[5] = {1, 2, 3, 4, 5};
	int *ptr = (int *)(&array + 1);
	char a[5] = {'a', 'b', 'c', 'd'};
	char (*ptr3)[3] = &a;
	char (*ptr4)[3] = a;
	long *ptr5 = (long *)(&array+1);
	long *ptr6 = (long *)((long)array+1);
	lk_print("%x, %x.\n", ptr5[-1], *ptr6);

	lk_print("%d, %d.\n", *(array+1), *(ptr-1));
	lk_print("%p, %p, %p.\n", a, ptr3+1, ptr4+1);

	lk_print("p1 = %p.\n", p1);
	*p = 0x010;
	lk_print("i = 0x%x, p = %p.\n", i, p);
	*p = NULL;
	lk_print("p = %p, *p = %x.\n", p, *p);
	p = NULL;
	lk_print("p = %p.\n", p);
	TwoD_array_test();
}

