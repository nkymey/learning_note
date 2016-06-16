#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "3.1.6_preprocess_undef.h"

#define X 3
#define Y X*2
#undef X
#define X 2
#ifdef X
#pragma message("I'm using Pragma message! X is defined.")
#endif

void preprocess_undef_test(void)
{
	int z = Y;
	printf("z = %d.\n", z);
}
