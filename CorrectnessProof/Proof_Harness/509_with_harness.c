#include <assert.h>
#include <stdlib.h>

int fib(int N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    return fib(N - 1) + fib(N - 2);
}

void proof_harness_fib() {
    int N;
    __CPROVER_assume(N >= 0);
    int expected = fib(N);
    int result = fib(N);
    assert(result == expected);
}

int main() {
    int N;
    __CPROVER_assume(N >= 0);
    int result = fib(N);
    return 0;
}

void proof_harness_main() {
    int N;
    __CPROVER_assume(N >= 0);
    main();
}

void combined_proof_harness() {
    proof_harness_fib();
    proof_harness_main();
}