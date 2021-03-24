#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "malg/meputil.h"
void randiarr(int* arr, size_t sz, int min, int max) {
    while (sz) arr[--sz] = (rand() % (max - min)) + min;
}

void randdarr(double* arr, size_t sz, double min, double max) {
    while (sz) {
        arr[--sz] = (((double)rand() / RAND_MAX) * (max - min)) + min;
    }
}

static const uint8_t DeBruijnMap32[32] = {
    0, 9,  1,  10, 13, 21, 2,  29, 11, 14, 16, 18, 22, 25, 3, 30,
    8, 12, 20, 28, 15, 17, 24, 7,  19, 27, 23, 6,  26, 5,  4, 31};

/** logarithm base 2 of a 32 bit int.
 * uses the DeBrujin method described
 * by Leiserson et al. in their 1998
 * paper. great trick and paper this
 * version is taken from "Bit Twiddling
 * Hacks"*/
uint8_t melog32(uint32_t v) {
    v |= v >> 1, v |= v >> 2;
    v |= v >> 4, v |= v >> 8;
    v |= v >> 16;

    return DeBruijnMap32[(uint32_t)(v * 0x07C4ACDDU) >> 27];
}

void dec2bstr(char* str, uint32_t n) {
    for (uint8_t b = 0; b < 32; ++b) {
        str[b] = (n % 2) + '0', n /= 2;
    }
}
