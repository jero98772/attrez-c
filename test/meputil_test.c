#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "malg/meputil.h"
#include "mstruct/mvec.h"
#include "test_tools.h"

MVEC(uint32_t, u)

mvecu t1vec;

uint32_t test1val = 65637;
void melog32_test1() {
    int r = rand() % 10000000;
    int a = log2(r);
    mvecu_pb(&t1vec, a);
}

void melog32_test2() {
    int r = rand() % 10000000;
    int a = melog32(r);
    mvecu_pb(&t1vec, a);
}

void melog32_test3() {
    int r = rand() % 10000000;
    int ans = melog32(r);
    int corr = log2(r);
    if (ans != corr) {
        printf("ans %i corr %i r %i", ans, corr, r);
    }
}

int main() {
    srand(time(NULL));
    mvecu_init(&t1vec, 10, NULL);
    // only run one of these first 2 at a time
    /*bench_time(melog32_test1, 10000000);*/
    /*bench_time(melog32_test2, 10000000);*/
    /*bench_time(melog32_test3, 1000);*/

    mvecu_destr(&t1vec, NULL);
}
