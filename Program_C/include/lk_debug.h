#ifndef __LK_DEUBG_H__
#define __LK_DEUBG_H__

#include <stdio.h>

#define pr_fmt(fmt) "%s():%d " fmt, __func__, __LINE__
#define lk_print(fmt, ...) printf(pr_fmt(fmt), ##__VA_ARGS__)

#endif
