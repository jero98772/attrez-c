#ifndef MVEC_H
#define MVEC_H

/*  a vector, as in a dynamically sized array.
 * it allows you to store items of type TYPE.
 * when the vector becomes full, it increases
 * the capacity of the underlying array by
 * GROWTH_MULT
 *
 * TODO:
 * - prolly make it so that pop can shrink
 * the vector if its capacity is twice its size
 * or something....also make it so that this can
 * be set at init */

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define GROWTH_MULT 1.5

#define MVEC_DECL(TYPE, NAME)                          \
    typedef struct {                                   \
        size_t sz, cap;                                \
        TYPE *dat;                                     \
    } mvec##NAME;                                      \
                                                       \
    void mvec##NAME##_init(mvec##NAME *, size_t, ...); \
    void mvec##NAME##_resz(mvec##NAME *, size_t);      \
    mvec##NAME mvec##NAME##_cp(mvec##NAME *);          \
    void mvec##NAME##_pb(mvec##NAME *, TYPE);          \
    TYPE *mvec##NAME##_ba(mvec##NAME *);               \
    void mvec##NAME##_pop(mvec##NAME *);               \
    void mvec##NAME##_destr(mvec##NAME *, ...);

#define MVEC_IMPL(TYPE, NAME)                                        \
    void mvec##NAME##_init(mvec##NAME *v, size_t cap, ...) {         \
        v->dat = (TYPE *)malloc(cap * sizeof(TYPE));                 \
                                                                     \
        v->sz = 0, v->cap = cap;                                     \
    }                                                                \
                                                                     \
    void mvec##NAME##_resz(mvec##NAME *v, size_t cap) {              \
        v->dat = (TYPE *)realloc(v->dat, sizeof(TYPE) * cap);        \
        if (v->sz > cap) v->sz = cap;                                \
        v->cap = cap;                                                \
    }                                                                \
    mvec##NAME mvec##NAME##_cp(mvec##NAME *v) {                      \
        mvec##NAME ret;                                              \
        mvec##NAME##_init(&ret, v->cap);                             \
        memcpy(ret.dat, v->dat, v->sz * sizeof(TYPE));               \
        return ret;                                                  \
    }                                                                \
                                                                     \
    void mvec##NAME##_pb(mvec##NAME *v, TYPE elem) {                 \
        if (v->sz >= v->cap) {                                       \
            v->cap *= GROWTH_MULT;                                   \
            v->dat = (TYPE *)realloc(v->dat, sizeof(TYPE) * v->cap); \
        }                                                            \
                                                                     \
        v->dat[v->sz++] = elem;                                      \
    }                                                                \
                                                                     \
    TYPE *mvec##NAME##_ba(mvec##NAME *vec) {                         \
        return &(vec->dat)[vec->sz - 1];                             \
    }                                                                \
                                                                     \
    void mvec##NAME##_pop(mvec##NAME *vec) {                         \
        (vec->sz) -= (size_t)(vec->sz > 0);                          \
    }                                                                \
                                                                     \
    void mvec##NAME##_destr(mvec##NAME *vec, void (*df)(TYPE *)) {   \
        size_t i;                                                    \
        if (df != NULL) {                                            \
            for (i = 0; i < vec->sz; ++i) df(&(vec->dat[i]));        \
        }                                                            \
        free(vec->dat);                                              \
    }

#define MVEC(TYPE, NAME)  \
    MVEC_DECL(TYPE, NAME) \
    MVEC_IMPL(TYPE, NAME)

#endif
