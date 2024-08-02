

#include <math.h> 
#include <stdio.h> 
#include <assert.h> 


int fib(unsigned int n) {
    float seq = (1 / sqrt(5) * pow(((1 + sqrt(5)) / 2), n + 1)) - (1 / sqrt(5) * pow(((1 - sqrt(5)) / 2), n + 1));

    
    return seq;
}


static void test () {
    
    assert(fib(0) == 1);
    assert(fib(1) == 1);
    assert(fib(2) == 2);
    assert(fib(3) == 3);
    assert(fib(4) == 5);
    assert(fib(5) == 8);
    assert(fib(6) == 13);
    assert(fib(7) == 21);
    assert(fib(8) == 34);
    assert(fib(9) == 55);
    assert(fib(10) == 89);
    
    printf("All tests have successfully passed!\n");
}


int main() {
    test();  

    for(int i = 0; i <= 10; i++){
        printf("%d. fibonacci number is: %d\n", i, fib(i));
    }
    return 0;
}
