#include <stdio.h>
#include <assert.h>

int sum(int a, int b) {
    int total = 0;
    for (int i = a; i < b; i++) {
        total += i;
    }
    return total;
}


int main() {
    
    assert(sum(2,5) == 2+3+4); //regular
    assert(sum(2,2) == 0); //empty
    assert(sum(-2,1) == (-2)+(-1)+0); //negatives
    assert(sum(3,2) == 0); //reversed
    assert(sum(2,3) == 2); //single element
    
    printf("All tests passed\n");

    return 0;
}
