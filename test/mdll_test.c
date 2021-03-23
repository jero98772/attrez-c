#include "mstruct/mdll.h"

#include <stdio.h>
MDLLIST(int, i)

void print_mdlli(mdlli *t) {
    printf("size %i\n", t->sz);
    for (int i = 0; i < t->sz; ++i) {
        printf("num %i ", *mdlli_at(t, i));
    }
    printf("\n");
}

void test1() {
    mdlli t;
    mdlli_init(&t);

    for (int i = 0; i < 100; ++i) {
        mdlli_pushb(&t, i);
    }
    print_mdlli(&t);

    for (int i = 0; i < 10; i++) {
        mdlli_popf(&t);
        mdlli_popb(&t);
    }
    print_mdlli(&t);
    mdlli_destroy(&t);
}

int main() { test1(); }
