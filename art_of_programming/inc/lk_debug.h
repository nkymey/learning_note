#ifndef __LK_DEUBG_H__
#define __LK_DEUBG_H__

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define pr_fmt(fmt) "%s():%d " fmt, __func__, __LINE__
#define lk_print(fmt, ...) printf(pr_fmt(fmt), ##__VA_ARGS__)
#define _ASSERT(e) if((e)) printf("Assert: func:%s, line:%d.\n", __func__, __LINE__)
#else
#define lk_print(fmt, ...)
#define _ASSERT(e)
#endif

#endif
