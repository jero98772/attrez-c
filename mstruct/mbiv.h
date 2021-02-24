#ifndef MMMBIV_H_
#define MMMBIV_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t *d;
    size_t sz;
} mbiv;

void mbiv_init(mbiv*, size_t);
void mbiv_resz(mbiv*, size_t);
bool mbiv_at(mbiv*, size_t);
void mbiv_set(mbiv*, size_t, bool);
void mbiv_destr(mbiv*);

#endif
