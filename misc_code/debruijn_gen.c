#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>


int indexarr[64];

uint64_t debruijn = 151050438420815295;


int main() {
    memset(indexarr, 0, sizeof indexarr);

    for(int i = 0; i < 64; ++i) {
        size_t ind = (debruijn << i) >> 58; 
        indexarr[ind] = i;
        printf("i: %i ind: %li\n", i, ind);

    }
    
}
