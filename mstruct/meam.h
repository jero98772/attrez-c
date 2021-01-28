#ifndef MEAM_H
#define MEAM_H

/*  * an adjacency matrix representation for a graph.
 * each node contains data of type TYPE, the graph
 * also stores how many edges start at the node */

#include <stdbool.h>
#include <stdlib.h>

#define MEAMAT_DECL(TYPE, NAME)                  \
    typedef struct {                             \
        int verts, edges, *venum;                \
        TYPE *dat;                               \
        bool *am;                                \
    } meam##NAME;                                 \
    void meam##NAME##_init(meam##NAME *, int);     \
    void meam##NAME##_add(meam##NAME *, int, int); \
    void meam##NAME##_del(meam##NAME *, int, int); \
    bool *meam##NAME##_ch(meam##NAME *, int);      \
    void meam##NAME##_destroy(meam##NAME *);

#define MEAMAT_IMPL(TYPE, NAME)                        \
    void meam##NAME##_init(meam##NAME *g, int v) {       \
        g->verts = v, g->edges = 0;                    \
        g->venum = (int *)calloc(v, sizeof(int));      \
        g->dat = (TYPE *)malloc(v * sizeof(TYPE));     \
        g->am = (bool *)calloc(v * v, sizeof(bool));   \
    }                                                  \
                                                       \
    void meam##NAME##_add(meam##NAME *g, int u, int w) { \
        if (!(g->am[g->verts * u + w])) {              \
            g->am[g->verts * u + w] = true;            \
            ++(g->venum[u]), ++(g->edges);             \
        }                                              \
    }                                                  \
                                                       \
    void meam##NAME##_del(meam##NAME *g, int u, int w) { \
        if (g->am[g->verts * u + w]) {                 \
            g->am[g->verts * u + w] = false;           \
            --(g->venum[u]), --(g->edges);             \
        }                                              \
    }                                                  \
                                                       \
    inline bool *meam##NAME##_ch(meam##NAME *g, int u) { \
        return g->am + (g->verts * u);                 \
    }                                                  \
                                                       \
    void meam##NAME##_destroy(meam##NAME *g) {           \
        free(g->dat), free(g->am);                     \
        free(g->venum);                                \
    }

#define MEAMAT(TYPE, NAME)  \
    MEAMAT_DECL(TYPE, NAME) \
    MEAMAT_IMPL(TYPE, NAME)

#endif
