#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "malg/meputil.h"

// you need a bit to tell if its occupied
// and its different from the bit that
// indicates if the first member of the
// neighbourhood that starts there is occupied

static const size_t NEIGH_SZ = 4;

typedef struct {
    int k, v;
} kvp;

typedef struct {
    kvp* d;
    uint32_t* info;
    size_t sz, load;
} hhh;

size_t hash(int i) {
    switch (i) {
        case 1:
        case 2:  // a, b
            return 0;
        case 3:  // c
            return 1;
        case 4:  // d
            return 2;
        case 5:
        case 6:  // e, f
            return 3;
        case 7:  // g
            return 4;
    };

    return i;
}

void hhh_init(hhh* ht, size_t sz) {
    ht->d = (kvp*)malloc(sz * sizeof(kvp));
    ht->info = (uint32_t*)calloc(sz, sizeof(kvp));
    ht->sz = sz, ht->load = 0;
}

// extreme cringe
// add inline later in header
size_t buck_dist(size_t b1, size_t b2, size_t sz) {
    if (b2 >= b1) return b2 - b1;
    return b2 + (sz - b1);
}

// extreme cringe 2
// add inline later in header
size_t wrap_sub(size_t pos, size_t dist, size_t sz) {
    return (size_t)(sz * (dist > pos) + pos) - dist;
}

void hhh_add(hhh* ht, int key, int val) {
    size_t start, srch, pos;
    uint8_t dist, max_dist;

    pos = hash(key) % ht->sz;
    if (!(ht->info[pos] & 1)) {
        ht->d[pos].k = key;
        ht->d[pos].v = val;
        ht->info[pos] |= 1;
        return;
    }

    start = (pos + 1) % ht->sz;

    // first bit indicates if full
    while (ht->info[start] & 1) {
        /*printf("%i\n", ht->info[start] & 1);*/
        start = (start < ht->sz) * (start + 1);

        if (start == pos) {
            puts("i need a rehash 1");
            return;
        }  // rehash
    }

    srch = wrap_sub(start, NEIGH_SZ - 1, ht->sz);

    while ((dist = buck_dist(pos, start, ht->sz)) > (NEIGH_SZ - 1)) {
        if (srch == start) {
            puts("i need a rehash 2");
            return;
        }  // rehash

        // start from second bit, since the first bit might
        // be on if its full, but the thing in it might not
        // hash there
        dist = 1, max_dist = buck_dist(srch, start, ht->sz);
        while (dist < max_dist && !(ht->info[srch] & (1 << dist))) ++dist;

        if (dist == max_dist) {
             srch = (srch < ht->sz) * (srch + 1);
        } else {
            ht->d[start] = ht->d[(srch + dist) % ht->sz];  // copy data
            ht->info[start] |= 1;  // we indicate its full now

            // turn off dist position, since that goes in that
            // empty space might not hash there
            ht->info[srch] &= ~(1 << dist);
            ht->info[srch] |= 1 << max_dist;  // indicate the hole is now taken

            // dont have to deal with the bits at the new start
            // since it will also be occupied eventually, (or get rehashed)
            // and the element put inside it doesnt hash there. this is because
            // the element that goes in that new start is either another element
            // that will be swapped or our val.

            start = (srch + dist) % ht->sz;
        }
    }

    ht->info[pos] |= 1 << (dist + 1), ht->info[start] |= 1;
    ht->d[start].k = key, ht->d[start].v = val;
}

void hhh_debugp(const hhh* ht) {
    char bin[33] = {0};
    puts("HASHTABLE START------------------------------");
    for (size_t i = 0; i < ht->sz; ++i) {
        int key = ht->d[i].k, val = ht->d[i].v;
        dec2bstr(bin, ht->info[i]);
        printf("%lu k: %i v: %i info: %s\n", i, key, val, bin);
    }

    puts("HASHTABLE END--------------------------------");
}

void buck_dist_test() {
    size_t a, b, sz = 2000;

    for (a = 0; a < sz; ++a) {
        for (b = 0; b < sz; ++b) {
            int ans = 0;
            while ((a + ans) % sz != b) ++ans;

            size_t out = buck_dist(a, b, sz);
            /*printf("%lu %lu\r", a, b);*/

            if ((size_t)ans != out) {
                printf("%lu and %lu gave %lu, expected %i\n", a, b, out, ans);
            }
        }
    }
}

void wrap_sub_test() {
    size_t a, b, sz = 2000;

    for (a = 0; a < sz; ++a) {
        for (b = 0; b < sz; ++b) {
            int ans = a, bcpy = b;
            while (bcpy-- > 0) {
                if (ans == 0)
                    ans = sz - 1;
                else
                    --ans;
            }

            size_t out = wrap_sub(a, b, sz);

            /*printf("%lu %lu\r", a, b);*/

            if ((size_t)ans != out) {
                printf("%lu and %lu gave %lu, expected %i\n", a, b, out, ans);
            }
        }
    }
}

void hhh_add_test() {
    hhh ht;
    hhh_init(&ht, 20);
    /*hhh_debugp(&ht);*/

    /*hhh_add(&ht, 3, 1);*/
    /*hhh_debugp(&ht);*/

    for (int i = 1; i <= 4; ++i) {
        hhh_add(&ht, i, i);
        hhh_debugp(&ht);
    }
}

int main() {
    /*buck_dist_test();  // wunderbar*/
    /*puts("buck_dist_test done");*/
    /*wrap_sub_test();*/
    hhh_add_test();
}
