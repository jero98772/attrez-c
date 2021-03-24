#include <stdbool.h>
#include <stdio.h>

#include "malg/meputil.h"
#include "mstruct/mbiv.h"
#include "test_tools.h"

void test1() {
    int i, sz = 100;
    int rands[sz + 1];
    mbiv b;

    randiarr(rands, sz, 0, 100);

    mbiv_init(&b, sz);
    printf("size is %i*8 = %i\n", b.sz, b.sz * 32);

    for (i = 0; i < sz; ++i) {
        printf("%i\n", rands[i]);
        mbiv_set(&b, rands[i], true);
    }

    for (i = 0; i < sz; ++i) {
        bool val = mbiv_at(&b, rands[i]);
        if (!val) {
            printf("%i not set to 1\n", rands[i]);
        }
    }

    for (i = 0; i < sz; ++i) {
        uint32_t val = b.d[i];

        for (int j = 0; j < 32; ++j) {
            size_t pos = i * 32 + j;
            uint32_t real = val & (1 << j);
            bool exp = mbiv_at(&b, pos);
            if ((bool)real != exp) {
                printf("error pos %u, %i != exp %i", pos, (bool)real, exp);
            }
        }
    }
}

int main() { test1(); }
