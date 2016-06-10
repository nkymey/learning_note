#include <stdio.h>
#include "lk_debug.h"
#include "0.0.0_helloworld.h"
#include "1.3.1_keyword_static.h"
#include "1.4.0_keyword_unsigned.h"
#include "1.5.2_keyword_sizeof.h"
#include "1.6.0_keyword_ifelse.h"
#include "1.15.0_keyword_union.h"

int main(void)
{
	lk_print("This's the main entry!\n");
//	print_hello();
//	keyword_static();
//	keyword_sizeof_test();
//	keyword_unsigned_test();
//	keyword_ifelse_test();
	keyword_union_test();

	return 0;
}
