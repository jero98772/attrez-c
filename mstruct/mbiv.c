#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "mbiv.h"

void mbiv_init(mbiv* b, size_t s) {
    b->sz = (s / 32) + 1;
    b->d = (uint32_t*) calloc(b->sz, sizeof(uint32_t));
}

void mbiv_resz(mbiv* b, size_t s) {
    b->sz = (s / 32) + 1;
    b->d = (uint32_t*)realloc(b->d, b->sz * sizeof(uint32_t));
}

bool mbiv_at(mbiv* b, size_t p) {
    uint32_t sect = b->d[p / 32];
    return (sect & (1 << p % 32)) > 0;
}

void mbiv_set(mbiv* b, size_t p, bool v) {
    uint32_t* sect = &(b->d[p / 32]);

    // theres prolly a 
    // branchless version of this,
    // ill do it later for fun

    if (v) {
        *sect = (*sect | (1 << (p % 32)));
    } else {
        *sect = (*sect & ~(1 << (p % 32)));
    }
}

void mbiv_destr(mbiv* b) { free(b->d); }
