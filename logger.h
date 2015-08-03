/*
 * Simple logging function to make prints to std pretty.
 */
#include <stdio.h>

#define dbg_printf(fmt, args... )\
  do{\
    printf("%s: %s(%i): "fmt, __FILE__, __func__, __LINE__, ##args);\
    printf("\n");\
  }\
  while(0)
