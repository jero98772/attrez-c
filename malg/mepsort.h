/* TODO
 * - add quick sort
 * - document code 
 * - add radix sort  */


#ifndef MEPSORT_H
#define MEPSORT_H

/* just some useful sorting algorithms */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* default comparison operations for
 * generic functions */
#define DEFAULT_COMP_DECL(TYPE, NAME)  \
    bool definc##NAME(TYPE *, TYPE *); \
    bool defdec##NAME(TYPE *, TYPE *);

#define DEFAULT_COMP_IMPL(TYPE, NAME)                       \
    bool definc##NAME(TYPE *a, TYPE *b) { return *a > *b; } \
    bool defdec##NAME(TYPE *a, TYPE *b) { return *a < *b; }

#define DEFAULT_COMP(TYPE, NAME)  \
    DEFAULT_COMP_DECL(TYPE, NAME) \
    DEFAULT_COMP_IMPL(TYPE, NAME)
// ------------------------------------------------------------

/* generalized insertion sort*/
#define INSORT_DECL(TYPE, NAME) \
    void insort##NAME(TYPE *, size_t, bool (*comp)(TYPE *, TYPE *));

#define INSORT_IMPL(TYPE, NAME)                                             \
    void insort##NAME(TYPE *arr, size_t sz, bool (*comp)(TYPE *, TYPE *)) { \
        TYPE key = arr[1];                                                  \
        if (comp(arr, &key)) arr[1] = arr[0], arr[0] = key;                 \
                                                                            \
        for (size_t i = 2; i < sz; ++i) {                                   \
            TYPE key = arr[i];                                              \
            size_t j = i;                                                   \
            bool state;                                                     \
            do {                                                            \
                state = false;                                              \
                if (!comp(&arr[--j], &key)) break;                          \
                arr[j + 1] = arr[j], state = true;                          \
            } while (j);                                                    \
            (state) ? (arr[0] = key) : (arr[j + 1] = key);                  \
        }                                                                   \
    }

#define INSORT(TYPE, NAME)  \
    INSORT_DECL(TYPE, NAME) \
    INSORT_IMPL(TYPE, NAME)
// ------------------------------------------------------------

/* merge sort */
#define MERSORT_DECL(TYPE, NAME)                                            \
    void merge##NAME(TYPE *, size_t, size_t, bool (*comp)(TYPE *, TYPE *)); \
                                                                            \
    void mersort##NAME(TYPE *, size_t, bool (*comp)(TYPE *, TYPE *));

#define MERSORT_IMPL(TYPE, NAME)                                             \
    void merge##NAME(TYPE *arr, size_t q, size_t r,                          \
                     bool (*comp)(TYPE *, TYPE *)) {                         \
        size_t n1 = q, n2 = r - q;                                           \
        TYPE *larr, *rarr;                                                   \
        larr = (TYPE *)malloc(n1 * sizeof(TYPE));                            \
        rarr = (TYPE *)malloc(n2 * sizeof(TYPE));                            \
                                                                             \
        memcpy(larr, arr, sizeof(TYPE) * n1);                                \
        memcpy(rarr, arr + q, sizeof(TYPE) * n2);                            \
                                                                             \
        size_t i = 0, j = 0;                                                 \
        for (size_t k = 0; k < r; ++k) {                                     \
            if (i >= n1) {                                                   \
                arr[k] = rarr[j++];                                          \
            } else if (j >= n2) {                                            \
                arr[k] = larr[i++];                                          \
            } else {                                                         \
                if (comp(&larr[i], &rarr[j])) {                              \
                    arr[k] = rarr[j++];                                      \
                } else {                                                     \
                    arr[k] = larr[i++];                                      \
                }                                                            \
            }                                                                \
        }                                                                    \
        free(larr), free(rarr);                                              \
    }                                                                        \
                                                                             \
    void mersort##NAME(TYPE *arr, size_t sz, bool (*comp)(TYPE *, TYPE *)) { \
        if (sz > 1) {                                                        \
            size_t q = sz / 2;                                               \
            mersort##NAME(arr, q, comp);                                     \
            mersort##NAME(arr + q, sz - q, comp);                            \
            merge##NAME(arr, q, sz, comp);                                   \
        }                                                                    \
    }

#define MERSORT(TYPE, NAME)  \
    MERSORT_DECL(TYPE, NAME) \
    MERSORT_IMPL(TYPE, NAME)

#endif
