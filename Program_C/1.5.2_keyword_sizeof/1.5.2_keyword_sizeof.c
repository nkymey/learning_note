#include <stdio.h>
#include "lk_debug.h"
#include "1.5.2_keyword_sizeof.h"

//int b[2][3];

static void sizeof_func(int b[2][3])
{
	int **p = NULL;
	lk_print("=== int **p = NULL;\n");
	p = (void *)&b;
	lk_print("sizeof(**b):%ld, **b:%d\n", sizeof(**b), **b /**(*(b + 1) + 2)*/);   /* **b: b[0], int type is 4 Bytes. */
	lk_print("sizeof(*(b+1)):%ld, *(b+1):%p\n", sizeof(*(b+1)), *(b+1));     /* *b: the address of b[0], 3*4=12. */
	lk_print("sizeof(b):%ld, b:%p\n", sizeof(b), b);   /* b: the address of array b, in 64bit system is 8 Bytes. */
	lk_print("=== p = &b\n");
	lk_print("sizeof(p):%ld, p:%p\n", sizeof(p), p);     /* p: b. */
	lk_print("sizeof(*p):%ld, *p:%p\n", sizeof(*p), *p);   /* *p: *b. */
	lk_print("sizeof(**p):%ld, **p:%d\n", sizeof(**p), **p/**(*p + 5)*/); /* **p: **b. */
}

void keyword_sizeof_test(void)
{
	int *p = NULL;
	int array[2][3] = {{0, 1, 2}, {3, 4, 5}};
	lk_print("=== int *p = NULL;\n");
	lk_print("sizeof(p):%ld\n", sizeof(p));
	lk_print("sizeof(*p):%ld.\n", sizeof(*p));
	lk_print("=== int array[2][3] = {0-5};\n");
	lk_print("sizeof(array):%ld, %p\n", sizeof(array), array);
	lk_print("sizeof(array[1]):%ld, %p, &array[1][0]: %p.\n", sizeof(array[1]), array[1], &array[1][0]);
	lk_print("sizeof(&array):%ld, &array: %p\n", sizeof(&array), &array);
	lk_print("sizeof(&array[0]):%ld\n", sizeof(&array[0]));
	sizeof_func(array);
}
