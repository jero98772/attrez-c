#include <stdio.h>
#include <time.h>

#include <chrono>

#include "../../cpp-code/n_arrays/fmot/fmot.h"
using namespace std;

void cpp_bench(void (*func)(), int times) {
    double total = 0.0;
    int timescpy = times;
    while (times--) {
        /*printf("left %i\n", times);*/
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        func();
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        total += chrono::duration_cast<std::chrono::milliseconds>(end - begin)
                     .count();
    }

    printf("average %f\n", (total / timescpy)/1000);
}

void bench_time(void (*func)(), int times) {
    double total = 0.0;
    int timescpy = times;
    while (times--) {
        double start = (float)clock() / CLOCKS_PER_SEC;
        func();
        double end = (float)clock() / CLOCKS_PER_SEC;
        total += end - start;
    }

    printf("average %f\n", total / timescpy);
}

int test1_rows = 500, test1_cols = 500;

void test1() {
    fmot<int> t(test1_rows, test1_cols);

    for (int i = 0; i < t.rows(); ++i) {
        for (int j = 0; j < t.cols(); ++j) {
            t[i][j] = i * j;
        }
    }
}

void test3() {
    fmot<int> t3(1000, 1000);
    for (int i = 0; i < t3.rows(); ++i) {
        for (int j = 0; j < t3.cols(); ++j) {
            t3[i][j] = i * j;
        }
    }

    for (int i = 0; i < t3.rows(); ++i) {
        for (int j = 0; j < t3.cols(); ++j) {
            t3[i][j] += 5000;
        }
    }

    for (int i = 0; i < t3.rows(); ++i) {
        for (int j = 0; j < t3.cols(); ++j) {
            bool s = t3[i][j] > 5000;
        }
    }
}

int main() { cpp_bench(test3, 1000); }
// int main() {
//// test1();
//// bench_time(test1, 1000);

// bench_time(test3, 1000);
//}
