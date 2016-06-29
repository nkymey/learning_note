#include <stdio.h>
#include "lk_debug.h"
#include "0.0.0_helloworld.h"
#include "1.3.1_keyword_static.h"
#include "1.4.0_keyword_unsigned.h"
#include "1.5.2_keyword_sizeof.h"
#include "1.6.0_keyword_ifelse.h"
#include "1.15.0_keyword_union.h"
#include "1.17.0_keyword_typedef.h"
#include "2.5.2_keyword_symbol.h"
#include "3.1.6_preprocess_undef.h"
#include "3.6.8_preprocess_memAlign.h"
#include "4.1.3_cpointer.h"
#include "4.6.1_array_pointer.h"


int main(void)
{
	lk_print("This's the main entry!\n");
//	print_hello();
//	keyword_static();
//	keyword_sizeof_test();
//	keyword_unsigned_test();
//	keyword_ifelse_test();
//	keyword_union_test();
//	keyword_typedef_test();
//	keyword_symbol_test();
	//preprocess_undef_test();
	//preprocess_memAlign_test();
	//cpointer_test();
	array_pointer_test();

	return 0;
}
