#include <time.h>

#include <cstdio>
#include <vector>
using namespace std;

void bench_time(void (*func)(), int times) {
    double total = 0.0;
    while (times--) {
                printf("left %i\n", times);
        double start = (float)clock() / CLOCKS_PER_SEC;
        func();
        double end = (float)clock() / CLOCKS_PER_SEC;
        total += end - start;
    }

    printf("average %f\n", total);
}

void test1() {
    vector<int> t;
    int i = 1;
    while (i < 10) {
        /*printf("cap %i\n", t.cap);*/
        t.push_back(3 * i++);
    }

    i = 1;
    while (i < 10) {
        /*printf("cap %i\n", t.cap);*/
        t.push_back(2 * i++);
    }

    /*print_mveci(&t);*/

    t.resize(5);

    i = 1;
    while (i < 20) {
        /*printf("cap %i\n", t.cap);*/
        t.push_back(5 * i++);
    }

    /*print_mveci(&t);*/
}

void test2() {
    vector<int> t;
    for (int i = 0; i < (int)(1e7); ++i) t.push_back(i);
}

int main() {
    // bench_time(test1, 100000);
    bench_time(test2, 100);
    //
}
