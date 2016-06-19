#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "3.6.8_preprocess_memAlign.h"


#pragma pack(16) /* 1, 2, 4, 8, 16 */

#define SQR(x) lk_print("The square of "#x" is %d.\n", ((x)*(x)))
#define XNAME(a, b) a##b

struct st_test1 {
	char a;
	long b;
};

struct st_test2 {
	char c;
	struct st_test1 d;
	long long e;
};

void preprocess_memAlign_test(void)
{
	struct st_test2 st_a;
	int abc = 345;
	lk_print("sizeof(long) = %ld.\n", sizeof(long));
	lk_print("sizeof(long long) = %ld.\n", sizeof(long long));
	lk_print("Sizeof(st_test2) = %ld.\n", sizeof(st_a));
	SQR(8);
	lk_print("ab##c = %d.\n", XNAME(ab, c));
}

#pragma pack()
