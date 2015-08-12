/*
 * Simple logging function to make prints to std pretty.
 */
#include <stdio.h>
extern int logging;

#define dbg_printf(fmt, args... )\
  do{\
    if (logging)\
    {\
      printf("%s: %s(%i): "fmt, __FILE__, __func__, __LINE__, ##args);\
      printf("\n");\
    }\
  }\
  while(0)
