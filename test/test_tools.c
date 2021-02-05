#include "test_tools.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "stdbool.h"

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

    printf("total: %f, average %f\n", total, total / timescpy);
}

void print_iarr(int *arr, size_t sz) {
    for (size_t i = 0; i < sz; ++i) printf("%i ", arr[i]);
    printf("\n");
}

void print_darr(double *arr, size_t sz) {
    for (size_t i = 0; i < sz; ++i) printf("%f ", arr[i]);
    printf("\n");
}

// naive shit way to eliminate repeats
// while i implement an actual set or somethin
int rem_repeats(int *arr, size_t sz) {
    bool reps[sz];
    memset(reps, false, sizeof reps);

    for (size_t i = 0; i < sz; ++i) {
        for (size_t j = i + 1; j < sz; ++j) {
            reps[j] = reps[j] || (arr[j] == arr[i]);
        }
    }

    int tind = 0, tmp[sz];
    for (size_t i = 0; i < sz; ++i) {
        if (!reps[i]) {
            tmp[tind] = arr[i], ++tind;
        }
    }

    memcpy(arr, tmp, tind * sizeof(int));
    return tind;
}
