#include <stdio.h>
#include "lk_debug.h"
#include "1.6.0_keyword_ifelse.h"


void keyword_ifelse_test(void)
{
	if(1)/* The complier give a warning here. */
	if(0) lk_print("Second if branch.\n");
	else {
		lk_print("else branch.\n");
	}
	//else ;/* avoid warning. */
	if(0);
		lk_print("Why printing me?\n");
	switch(1)
	{
		case 1:	/* char, int, constant. */
			lk_print("Don't forget the break and default in switch.\n");
			break;
		default:
			lk_print("default\n");
			break;
	}
}
