#include "fmat.h"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

FMAT(int, i)

void bench_time(void (*func)(), int times) {
    double total = 0.0;
    int timescpy = times;
    while (times--) {
        /*printf("left %i\n", times);*/
        double start = (float)clock() / CLOCKS_PER_SEC;
        func();
        double end = (float)clock() / CLOCKS_PER_SEC;
        total += end - start;
    }

    printf("average %f\n", total / timescpy);
}

void print_fmati(fmati *t) {
    printf("rows %i cols %i\n", t->rows, t->cols);

    for (int i = 0; i < t->rows; ++i) {
        for (int j = 0; j < t->cols; ++j) {
            int *pos = fmati_at(t, i, j);
            printf("%i ", *pos);
        }
        printf("\n");
    }
}

int ref_rows = 1000, ref_cols = 1000;
void ref_test() {
    int tr[ref_rows][ref_cols];
    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i][j] = i * j;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i][j] += 5000;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            bool s = tr[i][j] > 5000;
        }
    }

    /*print_fmati(&t);*/
}

void ref2test() {
    int tr[ref_rows * ref_cols];
    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i * ref_cols + j] = i * j;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i * ref_cols + j] += 5000;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            bool s = tr[i * ref_cols + j] > 5000;
        }
    }
}

int test1_rows = 1000, test1_cols = 1000;
void test1() {
    fmati t1;
    fmati_init(&t1, test1_rows, test1_cols);

    for (int i = 0; i < t1.rows; ++i) {
        for (int j = 0; j < t1.cols; ++j) {
            int *pos = fmati_at(&t1, i, j);
            *pos = i * j;
        }
    }

    for (int i = 0; i < t1.rows; ++i) {
        for (int j = 0; j < t1.cols; ++j) {
            int *pos = fmati_at(&t1, i, j);
            *pos += 5000;
        }
    }

    for (int i = 0; i < t1.rows; ++i) {
        for (int j = 0; j < t1.cols; ++j) {
            int *pos = fmati_at(&t1, i, j);
            bool s = *pos > 5000;
        }
    }

    /*print_fmati(&t);*/
    free(t1.mat);
}

int test2_rows = 1000, test2_cols = 1000;
void test2() {
    fmati t2;
    fmati_init(&t2, test2_rows, test2_cols);

    for (int i = 0; i < t2.rows; ++i) {
        for (int j = 0; j < t2.cols; ++j) {
            fmati_rp(&t2, i)[j] = i * j;
        }
    }

    for (int i = 0; i < t2.rows; ++i) {
        for (int j = 0; j < t2.cols; ++j) {
            fmati_rp(&t2, i)[j] += 5000;
        }
    }

    for (int i = 0; i < t2.rows; ++i) {
        for (int j = 0; j < t2.cols; ++j) {
            bool s = fmati_rp(&t2, i)[j] > 5000;
        }
    }

    /*print_fmati(&t);*/
    free(t2.mat);
}

fmati t3;
void test3() {
    for (int i = 0; i < t3.rows; ++i) {
        for (int j = 0; j < t3.cols; ++j) {
            fmati_rp(&t3, i)[j] = i * j;
        }
    }

    for (int i = 0; i < t3.rows; ++i) {
        for (int j = 0; j < t3.cols; ++j) {
            fmati_rp(&t3, i)[j] += 5000;
        }
    }

    for (int i = 0; i < t3.rows; ++i) {
        for (int j = 0; j < t3.cols; ++j) {
            bool s = fmati_rp(&t3, i)[j] > 5000;
        }
    }
}

int test4_rows = 1000, test4_cols = 1000;
void test4() {
    int **tr = (int **)malloc(test4_rows * sizeof(int *));
    for (int i = 0; i < ref_cols; ++i) {
        tr[i] = malloc(test4_cols * sizeof(int));
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i][j] = i * j;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            tr[i][j] += 5000;
        }
    }

    for (int i = 0; i < ref_rows; ++i) {
        for (int j = 0; j < ref_cols; ++j) {
            bool s = tr[i][j] > 5000;
        }
    }
}

int main() {
    /*printf("test1 ");    */
    /*bench_time(test1, 1000);*/

    /*printf("ref_test ");*/
    /*bench_time(ref_test, 1000);*/

    /*printf("ref2test ");*/
    /*bench_time(ref2test, 1000);*/

    /*printf("test4 ");    */
    bench_time(test4, 1000);

    /*printf("test2 ");    */
    /*bench_time(test2, 1000);*/
    
    /*printf("test3 ");    */
    /*fmati_init(&t3, 1000, 1000);*/
    /*bench_time(test3, 1000);*/
    /*free(t3.mat);*/
}
