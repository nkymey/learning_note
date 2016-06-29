#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "4.1.3_cpointer.h"

void fun_array(int a[10])
{
	int i = sizeof(a);
	lk_print("%p, sizeof(a): %d, a[3] = %d.\n", a, i, a[3]);
	a[3] = 10;
}

void fun_pointer(int *a)
{
	int i = sizeof(a);
	lk_print("%p, sizeof(a): %d, a[3] = %d.\n", a, i, a[3]);
	a[3] = 10;
}

void array_pointer_test(void)
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fun_array(array);
	lk_print("%p, array[3] = %d.\n", array, array[3]);
	fun_pointer(array);
	lk_print("%p, array[3] = %d.\n", array, array[3]);
}

