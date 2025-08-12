#include <assert.h>
#include <stdio.h>

int bitcount(int n){
    // 3 -> 11
    // 5 -> 101
    // 8 -> 1
    int total_bits = sizeof(n) * 8; // total bits in the type
    int res = 0;
    for (int i = total_bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1; // shift i bits right, mask with 1
        res += bit;
    }
    return res;
}


int main() {
    assert(bitcount(0) == 0);
    assert(bitcount(1) == 1);
    assert(bitcount(3) == 2);
    assert(bitcount(8) == 1);
    // harder case:
    assert(bitcount(0xffffffff) == 32);
    printf("OK\n");
}
