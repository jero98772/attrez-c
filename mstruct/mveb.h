#ifndef MVEB_H
#define MVEB_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
// a van emde boas tree
// in terms of sorting power, it seems to be able
// to beat my mergesort. however, because of the
// costly insertion process, its only useful if
// the program needs to sort on-line very large
// amounts of unique numbers

typedef struct s_mveb {
    struct s_mveb **clust;
    struct s_mveb *summ;
    size_t w_size;
    bool *init;
    uint32_t min, max;
} mveb;

mveb *mveb_init(size_t);

uint32_t mveb_succ(mveb *, uint32_t);

void mveb_insert(mveb *, uint32_t);

void mveb_del(mveb *, uint32_t);

void mveb_sorted(mveb *, uint32_t *, size_t);

void mveb_destroy(mveb *);

#endif
