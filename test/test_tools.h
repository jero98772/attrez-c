#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include <stddef.h>

// benchmark avg running time
void bench_time(void (*func)(), int);

// print array of ints
void print_iarr(int *, size_t);

// print array of doubles
void print_darr(double *, size_t);

// remove repeated numbers from an array
// of ints
int rem_repeats(int *, size_t);

#endif
