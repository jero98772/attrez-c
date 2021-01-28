#include "mveb.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mveb *mveb_init(size_t w_size) {
    mveb *v = malloc(sizeof(mveb));
    v->w_size = w_size;
    long usz = 1L << w_size;
    v->min = (uint32_t)(usz - 1), v->max = 0;

    if (w_size > 1) {
        long sqrt_usz = usz >> (w_size / 2);
        v->clust = malloc(sizeof(mveb *) * sqrt_usz);
        v->init = malloc(sizeof(bool) * sqrt_usz);
        memset(v->init, false, sizeof(bool) * sqrt_usz);
    }

    return v;
}

uint32_t mveb_succ(mveb *v, uint32_t x) {
    if (v->min > x) return v->min;
    if (v->max <= x) return 0;

    // if size is 1, and x is not smaler than min
    // and also not equal to max, then min and max
    // are not equal and x must be 0

    if (v->w_size == 1) return 1;

    uint32_t c = x >> (v->w_size / 2);
    uint32_t lo = x & ((1 << (v->w_size / 2)) - 1);
    mveb *cclust = (v->clust)[c];

    if (v->init[c] && lo < cclust->max) {
        return (c << (v->w_size / 2)) | mveb_succ(cclust, lo);
    }

    uint32_t s = mveb_succ(v->summ, c);
    return (s << (v->w_size / 2)) | (v->clust)[s]->min;
}

void mveb_insert(mveb *v, uint32_t x) {
    // because of the way we init w_size == 1,
    // it doesnt enter here ever.
    if (v->max < v->min) {
        v->max = v->min = x;
        if (v->w_size > 1) v->summ = mveb_init(v->w_size / 2);
        return;
    }

    if (v->min > x) {
        uint32_t tmp = v->min;
        v->min = x, x = tmp;
    }

    if (v->max < x) v->max = x;
    if (v->w_size <= 1) return;

    uint32_t c = x >> (v->w_size / 2);
    uint32_t lo = x & ((1 << (v->w_size / 2)) - 1);

    if (!v->init[c]) {
        (v->clust)[c] = mveb_init(v->w_size / 2);
        v->init[c] = true;
    }

    mveb *cclust = (v->clust)[c];
    mveb_insert(cclust, lo);
    if (cclust->max == cclust->min) mveb_insert(v->summ, c);
}

void mveb_del(mveb *v, uint32_t x) {
    if (v->min == x && v->max == x) {
        v->max = 0, v->min = 1;  // mark for death
        if (v->w_size > 1) free(v->summ);
        return;
    }

    if (v->w_size == 1) {
        v->min = v->max = !x;
        return;
    }

    if (v->min == x) {
        size_t i = (v->summ)->min;
        v->min = x = (i << (v->w_size / 2)) | (v->clust[i])->min;
    }

    uint32_t c = x >> (v->w_size / 2);
    uint32_t lo = x & ((1 << (v->w_size / 2)) - 1);
    if (!v->init[c]) return;

    mveb *cclust = (v->clust)[c];
    mveb_del(cclust, lo);

    if (cclust->max < cclust->min) {
        mveb_del(v->summ, c), free(cclust);
        v->init[c] = false;
    }

    if (x == v->max) {
        if ((v->summ)->max < (v->summ)->min) {
            v->max = v->min;
        } else {
            size_t i = (v->summ)->max;
            v->max = (i << (v->w_size / 2)) | (v->clust[i])->min;
        }
    }
}

void mveb_sorted(mveb *v, uint32_t *arr, size_t sz) {
    uint32_t t = arr[0] = v->min;
    size_t i = 1;

    while (i < sz) {
        t = mveb_succ(v, t);
        if (t == 0) return;
        arr[i] = t, ++i;
    }
}

void mveb_destroy(mveb *v) {
    if (v->w_size == 1) {
        free(v);
    } else if (v->min > v->max) {
        free(v->clust), free(v->init);
        free(v);
    } else {
        unsigned long sqrt_usz = 1L << (v->w_size / 2);
        for (size_t i = 0; i < sqrt_usz; ++i) {
            if (v->init[i]) mveb_destroy(v->clust[i]);
        }
        mveb_destroy(v->summ), free(v->init);
        free(v->clust), free(v);
    }
}
