#include <stdio.h>
#include "lk_debug.h"
#include "1.3.1_keyword_static.h"

static int j;

static void static_func1(void)
{
	/* static i won't be destroyed even though the function running over. */
	static int i = 0;
	i++;
	lk_print("static int i =0; i++; print i = %d.\n", i);
}

static void static_func2(void)
{
	/* j is set to 0. */
	j = 0;
	j++;
	lk_print("static j = %d.\n", j);
}

int keyword_static(void)
{
	int k = 0;
	for(k = 0; k < 10; k++) {
		static_func1();
		static_func2();
	}
	return 0;
}
