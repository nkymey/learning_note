#include <stdio.h>
#include <string.h>
#include "lk_debug.h"
#include "4.7.2_pointer_fun.h"

char* compare_string(char* str_a, char* str_b)
{
	if(strcmp(str_a, str_b))
		return str_a;
	else
		return str_b;
}

char * fun1(char * p)
{
	lk_print("%s\n",p);
	return p;
}

char * fun2(char * p)
{
	lk_print("%s\n",p);
	return p;
}

char * fun3(char * p)
{
	lk_print("%s\n",p);
	return p;
}

void pointer_fun_test(void)
{
	char* result;
	char* (*pointer_fun)(char* str_a, char* str_b);	//函数指针
	char* (*a[3])(char* p);		//函数指针数组
	char* (*(*pf)[3])(char* p);	//函数指针数组指针

	//lk_print("sizeof(int) = %ld.\n", sizeof(int));
	pointer_fun = &compare_string;
	//*(int*)&pointer_fun = (int)compare_string;//表示将函数的入口地址赋值给指针变量 p
	result = (*pointer_fun)("aa", "bb");
	lk_print("result: %s.\n", result);

	pf = &a;
	a[0] = fun1;
	a[1] = &fun2;
	a[2] = &fun3;
	pf[0][0]("fun1");
	(**pf)("test");
	pf[0][1]("fun2");
	(*(*pf+1))("test2");
	pf[0][2]("fun3");
	(*(*pf+2))("test3");
}

