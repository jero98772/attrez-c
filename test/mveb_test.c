#include "mstruct/mveb.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "malg/mepsort.h"
#include "malg/meputil.h"
#include "test_tools.h"

DEFAULT_COMP(int, i)
MERSORT(int, i)

void test1() {
    mveb *a = mveb_init(32);
    puts("*******************************************");

    mveb_insert(a, 1);
    puts("--");
    mveb_insert(a, 2);
    puts("--");
    mveb_insert(a, 3);
    puts("--");
    mveb_insert(a, 4);
    puts("--");
    mveb_insert(a, 5);
    puts("--");
    mveb_insert(a, 6);
    puts("--");
    mveb_insert(a, 7);
    puts("--");

    puts("*******************************************");
    printf("%i ", mveb_succ(a, 5));
}

void test2() {
    mveb *a = mveb_init(32);
    for (int i = 70000; i >= 0; i -= 3) {
        mveb_insert(a, i);
    }
    puts("*******************************************");

    for (int i = 0; i < 70000; ++i) {
        printf("%i\n", mveb_succ(a, i));
        /*if (mveb_succ(a, i) != i + 1) puts("poop");*/
    }
}

void test3() {
    int arrsz = 5000, arr[arrsz];
    randiarr(arr, arrsz, 1, 10000);
    /*print_iarr(arr, arrsz);*/
    puts("NO REPEATS*******");

    arrsz = rem_repeats(arr, arrsz);
    /*print_iarr(arr, arrsz);*/

    puts("MERGE-SORTED*******");

    int sort1[arrsz], sort2[arrsz];
    /*memcpy(sort1, arr, arrsz * sizeof(int));*/

    /*mersorti(sort1, arrsz, definci);*/
    /*print_iarr(sort1, arrsz);*/

    puts("VEB-SORTED*******");

    mveb *a = mveb_init(32);
    for (int i = 0; i < arrsz; ++i) {
        mveb_insert(a, arr[i]);
    }

    mveb_sorted(a, (uint32_t *)sort2, arrsz);
    /*print_iarr(sort2, arrsz);*/

    for (int i = 0; i < arrsz - 1; ++i) {
        if (sort2[i] >= sort2[i + 1]) puts("hmmm kinda cringe");

        /*if (sort2[i] != sort1[i]) {*/
            /*printf("at %i: sort1 %i != sort2 %i\n", i, sort1[i], sort2[i]);*/
        /*}*/
    }
}

void test4(int times) {
    double total = 0.0;
    int timescpy = times;
    while (times--) {
        int arrsz = 10000, arr[arrsz];
        randiarr(arr, arrsz, 1, 10000);
        arrsz = rem_repeats(arr, arrsz);
        mveb *a = mveb_init(32);

        /*printf("left %i\n", times);*/
        double start = (float)clock() / CLOCKS_PER_SEC;
        int sortd[arrsz];
        for (int i = 0; i < arrsz; ++i) {
            mveb_insert(a, arr[i]);
        }

        mveb_sorted(a, (uint32_t *)sortd, arrsz);
        double end = (float)clock() / CLOCKS_PER_SEC;
        total += end - start;
    }

    printf("average %f\n", total / timescpy);
}

void test5() {
    int max = 5;
    mveb *a = mveb_init(32);
    for (int i = 0; i < max; ++i) {
        mveb_insert(a, i);
    }

    printf("%u\n", mveb_succ(a, 4));
    mveb_del(a, 5);

    printf("%u\n", mveb_succ(a, 4));
    mveb_del(a, 6);

    printf("%u\n", mveb_succ(a, 4));
    mveb_del(a, 7);

    printf("%u\n", mveb_succ(a, 4));
    mveb_del(a, 8);

    printf("%u\n", mveb_succ(a, 4));
    mveb_del(a, 9);
}

void test6() {
    while (1) {
        mveb *a = mveb_init(32);

        int arrsz = 100, arr[arrsz];
        randiarr(arr, arrsz, 1, 10000);
        arrsz = rem_repeats(arr, arrsz);

        for (int i = 0; i < arrsz; ++i) {
            mveb_insert(a, arr[i]);
        }

        mveb_destroy(a);
    }
}

int main() {
    srand(time(NULL));
    test1();
    test2();
    test3();
    test4(5);
    test5();
    test6();
}
