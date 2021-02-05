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
void randiarr(int*, size_t, int, int);

/** takes an array and its size and
 * fills it with random doubles in
 * a given range. relies on user
 * initializing seed. */
void randdarr(double*, size_t, double, double);

/** takes a 32 bit unsigned int
 * and returns its  base 2 logarithm
 * in an unsigned 8bit int*/
uint8_t melog32(uint32_t);i


/** takes a 64 bit unsigned int
 * and returns its base 2 logarithm
 * in an unsigned 8 bit int*/
uint8_t melog64(uint64_t);


#endif
