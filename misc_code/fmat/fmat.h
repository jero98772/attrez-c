#ifndef FMAT_H
#define FMAT_H
#include <stdlib.h>

#define FMAT_DECL(TYPE, NAME)                       \
    typedef struct {                                \
        int rows, cols;                             \
        TYPE *mat;                                  \
    } fmat##NAME;                                   \
                                                    \
    void fmat##NAME##_init(fmat##NAME *, int, int); \
    TYPE *fmat##NAME##_at(fmat##NAME *, int, int);  \
    TYPE *fmat##NAME##_rp(fmat##NAME *, int);

#define FMAT_IMPL(TYPE, NAME)                                    \
    void fmat##NAME##_init(fmat##NAME *fm, int rows, int cols) { \
        fm->rows = rows, fm->cols = cols;                        \
        fm->mat = (TYPE *)malloc(sizeof(TYPE) * rows * cols);    \
    }                                                            \
                                                                 \
    inline TYPE *fmat##NAME##_at(fmat##NAME *fm, int row, int col) {    \
        return fm->mat + (row * fm->cols) + col;                 \
    }                                                            \
                                                                 \
    inline TYPE *fmat##NAME##_rp(fmat##NAME *fm, int row) {             \
        return fm->mat + (row * fm->cols);                       \
    }

#define FMAT(TYPE, NAME)  \
    FMAT_DECL(TYPE, NAME) \
    FMAT_IMPL(TYPE, NAME)

#endif
