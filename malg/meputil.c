#include "meputil.h"

#include <stdlib.h>
void randiarr(int* arr, size_t sz, int min, int max) {
    while (--sz) arr[sz] = (rand() % (max - min)) + min;
    arr[0] = (rand() % (max - min)) + min;
}

void randdarr(double* arr, size_t sz, double min, double max) {
    while (--sz) {
        arr[sz] = (((double)rand() / RAND_MAX) * (max - min)) + min;
    }
    arr[0] = (((double)rand() / RAND_MAX) * (max - min)) + min;
}
