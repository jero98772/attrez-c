#include "../mstruct/meam.h"

#include <stdio.h>
#include <stdlib.h>

#include "test_tools.h"
MEAMAT(int, i)

void print_meami(meami *t) {
    for (int u = 0; u < t->verts; ++u) {
        bool *ch = meami_ch(t, u);
        printf("%i: ", u);
        for (int v = 0; v < t->verts; ++v) {
            printf("%i ", ch[v]);
        }
        printf("\n");
    }
}

void test1() {
    meami t;
    meami_init(&t, 6);
    meami_add(&t, 0, 1);
    meami_add(&t, 0, 2);
    meami_add(&t, 1, 2);
    meami_add(&t, 1, 3);
    meami_add(&t, 2, 3);
    meami_add(&t, 3, 0);
    meami_add(&t, 3, 4);
    meami_add(&t, 4, 2);
    meami_add(&t, 4, 5);
    meami_add(&t, 5, 2);
    meami_add(&t, 5, 0);

    print_meami(&t);
}

int main() { test1(); }
