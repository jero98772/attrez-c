/*
 * TODO:
 * - prolly make it so that pop can shrink
 * the vector if its capacity is twice its size
 * or something....also make it so that this can
 * be set at init  
 * - document
 * */

#ifndef MVEC_H
#define MVEC_H

/*  a vector, as in a dynamically sized array.
 * it allows you to store items of type TYPE.
 * when the vector becomes full, it increases
 * the capacity of the underlying array by
 * GROWTH_MULT */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static float MVEC_GROWTH_MULT = 1.5f;

#define MVEC_DECL(TYPE, NAME)                                          \
    typedef struct {                                                   \
        size_t sz, cap;                                                \
        void (*ifn)(TYPE *);                                           \
        TYPE *d;                                                       \
    } mvec##NAME;                                                      \
                                                                       \
    void mvec##NAME##_init(mvec##NAME *, size_t, void (*ifn)(TYPE *)); \
    void mvec##NAME##_resz(mvec##NAME *, size_t);                      \
    mvec##NAME mvec##NAME##_cp(const mvec##NAME *);                    \
    void mvec##NAME##_pb(mvec##NAME *, TYPE);                          \
    TYPE *mvec##NAME##_ba(mvec##NAME *);                               \
    void mvec##NAME##_pop(mvec##NAME *);                               \
    void mvec##NAME##_destr(mvec##NAME *, void (*df)(TYPE *));

#define MVEC_IMPL(TYPE, NAME)                                                \
    void mvec##NAME##_init(mvec##NAME *v, size_t cap, void (*ifn)(TYPE *)) { \
        v->d = (TYPE *)malloc(cap * sizeof(TYPE));                           \
        v->cap = cap, v->sz = 0, v->ifn = ifn;                               \
        while (ifn != NULL && (cap > 0)) ifn(v->d + --cap);                  \
    }                                                                        \
                                                                             \
    void mvec##NAME##_resz(mvec##NAME *v, size_t ncap) {                     \
        size_t szdif = (size_t)(ncap > v->cap) * (ncap - v->cap);            \
        v->d = (TYPE *)realloc(v->d, sizeof(TYPE) * ncap);                   \
        while (v->ifn != NULL && (szdif > 0)) {                              \
            v->ifn(v->d + v->cap + --szdif);                                 \
        }                                                                    \
        if ((v->cap = ncap) < v->sz) v->sz = v->cap;                         \
    }                                                                        \
                                                                             \
    mvec##NAME mvec##NAME##_cp(const mvec##NAME *v) {                        \
        mvec##NAME ret;                                                      \
        mvec##NAME##_init(&ret, v->cap, NULL);                               \
        memcpy(ret.d, v->d, v->cap * sizeof(TYPE));                          \
        ret.ifn = v->ifn; /*avoid running ifn unecessarily */                \
        return ret;                                                          \
    }                                                                        \
                                                                             \
    void mvec##NAME##_pb(mvec##NAME *v, TYPE elem) {                         \
        if (v->sz >= v->cap) {                                               \
            mvec##NAME##_resz(v, v->cap *MVEC_GROWTH_MULT);                  \
        }                                                                    \
        v->d[v->sz++] = elem;                                                \
    }                                                                        \
                                                                             \
    TYPE *mvec##NAME##_ba(mvec##NAME *v) { return v->d + v->sz - 1; }        \
                                                                             \
    void mvec##NAME##_pop(mvec##NAME *v) { (v->sz) -= (size_t)(v->sz > 0); } \
                                                                             \
    void mvec##NAME##_destr(mvec##NAME *v, void (*dfn)(TYPE *)) {            \
        while (dfn != NULL && (v->cap > 0)) dfn(v->d + --v->cap);            \
        free(v->d);                                                          \
    }

#define MVEC(TYPE, NAME)  \
    MVEC_DECL(TYPE, NAME) \
    MVEC_IMPL(TYPE, NAME)

#endif
