/* TODO 
   - 64 bit version of melog
   - make use of the generic macro so that 
   you only have to make one function call
   for 32 and 64 bit versions of this stuff.
   - *maybe* even add binary strings for
   signed numbers and doubles, and use generic
   for em too
*/

#ifndef MEPUTIL_H
#define MEPUTIL_H

/* just a collection of possibly
 * useful functions */
#include <stddef.h>
#include <stdint.h>
/** takes an array and its size
 * and fills it with random int's
 * in a given range. relies on user
 * initializing seed.*/
void randiarr(int *arr, size_t sz, int min, int max);

/** takes an array and its size and
 * fills it with random doubles in
 * a given range. relies on user
 * initializing seed. */
void randdarr(double *arr, size_t sz, double min, double max);

/** takes a 32 bit unsigned int
 * and returns its  base 2 logarithm
 * in an unsigned 8bit int*/
uint8_t melog32(uint32_t v);

/**
 * takes in a 32 bit unsigned int
 * and a pointer to an array of chars.
 * it writes the bit representation
 * to the array, from LSB to MSB*/
void dec2bstr(char *str, uint32_t n);


#endif
