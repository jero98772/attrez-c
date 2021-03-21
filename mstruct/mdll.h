/* TODO
 * - cleanup and documentation
 */
#ifndef MDLL_H
#define MDLL_H

/* 
 * ...a double-linked list*/

#include <stdlib.h>

#define MDLLIST_DECL(TYPE, NAME)                 \
    typedef struct s_mdllnd##NAME {              \
        TYPE dat;                                \
        struct s_mdllnd##NAME *prev, *next;      \
    } mdllnd##NAME;                              \
                                                 \
    typedef struct {                             \
        int sz;                                  \
        mdllnd##NAME *head, *tail;               \
    } mdll##NAME;                                \
                                                 \
    void mdll##NAME##_init(mdll##NAME *);        \
    TYPE *mdll##NAME##_at(mdll##NAME *, int);    \
    void mdll##NAME##_pushb(mdll##NAME *, TYPE); \
    void mdll##NAME##_pushf(mdll##NAME *, TYPE); \
    void mdll##NAME##_popb(mdll##NAME *);        \
    void mdll##NAME##_popf(mdll##NAME *);        \
    void mdll##NAME##_destroy(mdll##NAME *);

#define MDLLIST_IMPL(TYPE, NAME)                          \
    void mdll##NAME##_init(mdll##NAME *l) {               \
        l->sz = 0;                                        \
        l->head = NULL, l->tail = NULL;                   \
    }                                                     \
                                                          \
    TYPE *mdll##NAME##_at(mdll##NAME *l, int index) {     \
        mdllnd##NAME *tmp;                                \
        if (index < (l->sz - index - 1)) {                \
            tmp = l->head;                                \
            while (index--) tmp = tmp->next;              \
        } else {                                          \
            tmp = l->tail, index = l->sz - index - 1;     \
            while (index--) tmp = tmp->prev;              \
        }                                                 \
        return &(tmp->dat);                               \
    }                                                     \
                                                          \
    void mdll##NAME##_pushb(mdll##NAME *l, TYPE it) {     \
        mdllnd##NAME *ntail_item =                        \
            (mdllnd##NAME *)malloc(sizeof(mdllnd##NAME)); \
        ntail_item->next = NULL, ntail_item->prev = NULL; \
                                                          \
        if (l->tail != NULL) {                            \
            (l->tail)->next = ntail_item;                 \
            ntail_item->prev = l->tail;                   \
        }                                                 \
                                                          \
        l->tail = ntail_item, ++(l->sz);                  \
        (l->tail)->dat = it;                              \
        if (l->head == NULL) l->head = l->tail;           \
    }                                                     \
                                                          \
    void mdll##NAME##_pushf(mdll##NAME *l, TYPE it) {     \
        mdllnd##NAME *nhead_item =                        \
            (mdllnd##NAME *)malloc(sizeof(mdllnd##NAME)); \
        nhead_item->next = NULL, nhead_item->prev = NULL; \
                                                          \
        if (l->head != NULL) {                            \
            nhead_item->next = l->head;                   \
            (l->head)->prev = nhead_item;                 \
        }                                                 \
                                                          \
        l->head = nhead_item, ++(l->sz);                  \
        (l->head)->dat = it;                              \
        if (l->tail == NULL) l->tail = l->head;           \
    }                                                     \
                                                          \
    void mdll##NAME##_popb(mdll##NAME *l) {               \
        if (l->tail != NULL) {                            \
            mdllnd##NAME *tmp = l->tail;                  \
            l->tail = (l->tail)->prev, --(l->sz);         \
            free(tmp);                                    \
            if (l->sz > 0) {                              \
                (l->tail)->next = NULL;                   \
            } else {                                      \
                l->head = NULL;                           \
            }                                             \
        }                                                 \
    }                                                     \
                                                          \
    void mdll##NAME##_popf(mdll##NAME *l) {               \
        if (l->head != NULL) {                            \
            mdllnd##NAME *tmp = l->head;                  \
            l->head = (l->head)->next, --(l->sz);         \
            free(tmp);                                    \
            if (l->sz > 0) {                              \
                (l->head)->prev = NULL;                   \
            } else {                                      \
                l->tail = NULL;                           \
            }                                             \
        }                                                 \
    }                                                     \
                                                          \
    void mdll##NAME##_destroy(mdll##NAME *l) {            \
        while (l->sz) mdll##NAME##_popf(l);             \
    }

#define MDLLIST(TYPE, NAME)  \
    MDLLIST_DECL(TYPE, NAME) \
    MDLLIST_IMPL(TYPE, NAME)

#endif
