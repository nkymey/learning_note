#include <stdio.h>
#include "lk_debug.h"
#include "0.0.0_helloworld.h"
#include "1.3.1_keyword_static.h"

int main(void)
{
	lk_print("This's the main entry!\n");
	print_hello();
	keyword_static();

	return 0;
}
