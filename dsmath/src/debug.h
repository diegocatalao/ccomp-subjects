#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
#include "dsmath.h"

#ifndef DEBUG_H_
#define DEBUG_H_

void __print_str_datetime(char *s_message);
void debug_ftime(char* fname, void (*function)(void));

#endif