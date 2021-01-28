#include "../malg/mepsort.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../malg/meputil.h"
#include "test_tools.h"

DEFAULT_COMP(double, d)
INSORT(double, d)
MERSORT(double, d)

DEFAULT_COMP(int, i)
INSORT(int, i)
MERSORT(int, i)

// INSERTION SORTi---------------------------------------------
void test1_insort() {
    int arrsz = 21, arr[arrsz];
    randiarr(arr, arrsz, 1, 1000);
    print_iarr(arr, arrsz);

    insorti(arr, arrsz, definci);
    printf("\nsorted ");
    print_iarr(arr, arrsz);
}

void test2_insort() {
    int arrsz = 20;
    double arr[arrsz];
    randdarr(arr, arrsz, 1.0, 1000.0);
    print_darr(arr, arrsz);

    insortd(arr, arrsz, defincd);
    printf("\nsorted ");
    print_darr(arr, arrsz);

    insortd(arr, arrsz, defdecd);
    printf("\nsorted back ");
    print_darr(arr, arrsz);
}

// MERGE SORT--------------------------------------------------
void test1_mersort() {
    int arrsz = 1000, arr[arrsz];
    randiarr(arr, arrsz, 1, 1000);
    print_iarr(arr, arrsz);

    mersorti(arr, arrsz, definci);
    printf("\nsorted ");
    print_iarr(arr, arrsz);

    mersorti(arr, arrsz, defdeci);
    printf("\nsorted back");
    print_iarr(arr, arrsz);
}

void test2_mersort() {
    int arrsz = 27;
    double arr[arrsz];
    randdarr(arr, arrsz, 1, 1000);
    print_darr(arr, arrsz);

    mersortd(arr, arrsz, defincd);
    printf("\nsorted ");
    print_darr(arr, arrsz);

    mersortd(arr, arrsz, defdecd);
    printf("\nsorted back");
    print_darr(arr, arrsz);
}

void test3_mersort(int times) {
    double total = 0.0;
    int timescpy = times;
    while (times--) {
        int arrsz = 10000, arr[arrsz];
        randiarr(arr, arrsz, 1, 10000);
        arrsz = rem_repeats(arr, arrsz);

        /*printf("left %i\n", times);*/
        double start = (float)clock() / CLOCKS_PER_SEC;
        int sortd[arrsz];
        for(int i = 0; i < arrsz; ++i) {
            sortd[i] = arr[i];
        }

        mersorti(sortd, arrsz, definci);
        double end = (float)clock() / CLOCKS_PER_SEC;
        total += end - start;
    }

    printf("average %f\n", total / timescpy);
}

// ------------------------------------------------------------
int main() {
    srand(time(NULL));

    /*bench_time(test1_insort, 1);*/
    /*bench_time(test2_insort, 1);*/
    /*bench_time(test1_mersort, 1);*/
    /*bench_time(test2_mersort, 1);*/

    test3_mersort(100);
}
