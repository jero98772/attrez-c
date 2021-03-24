#include "mstruct/mvec.h"

#include <stdio.h>

#include "test_tools.h"
MVEC(int, i)
MVEC(mveci, vi)

void print_mveci(mveci *t) {
    printf("size %li cap %li\n", t->sz, t->cap);
    for (size_t i = 0; i < t->sz; ++i) {
        printf("%i ", t->d[i]);
    }
    printf("\n");
}

void test1() {
    mveci t;
    mveci_init(&t, 2, NULL);
    int i = 1;
    while (i < 10) {
        /*printf("cap %i\n", t.cap);*/
        mveci_pb(&t, 3 * i++);
    }

    i = 1;
    while (i < 10) {
        /*printf("cap %i\n", t.cap);*/
        mveci_pb(&t, 2 * i++);
    }

    /*print_mveci(&t);*/

    mveci_resz(&t, 5);
    /*print_mveci(&t);*/
    mveci_resz(&t, 20);
    /*print_mveci(&t);*/
    i = 1;
    while (i < 20) {
        /*printf("cap %i\n", t.cap);*/
        mveci_pb(&t, 5 * i++);
    }

    /*print_mveci(&t);*/
    mveci_destr(&t, NULL);
}

void test2() {
    mveci t;
    mveci_init(&t, 10, NULL);
    for (size_t i = 0; i < (size_t)(1e7); ++i) mveci_pb(&t, i);
    mveci_destr(&t, NULL);
}

#define TEST3NUM 1746327
void set2n(int *i) { *i = TEST3NUM; }

void test3() {
    mveci t;
    mveci_init(&t, 100, set2n);
    for (size_t i = 0; i < t.cap; ++i) {
        if (t.d[i] != TEST3NUM) printf("got %i in pos %li\n", t.d[i], i);
    }
    mveci_resz(&t, 200);
    printf("new cap %li\n", t.cap);
    for (size_t i = 0; i < t.cap; ++i) {
        if (t.d[i] != TEST3NUM) printf("got %i in pos %li\n", t.d[i], i);
    }
    /*mveci_destr(&t, NULL); */
}

int main() {
    bench_time(test1, 1);
    bench_time(test2, 1);
    test1();
    test2();
    test3();
}
