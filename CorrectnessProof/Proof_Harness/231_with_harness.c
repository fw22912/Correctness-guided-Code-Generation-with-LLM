#include <assert.h>
#include <stdbool.h>

// Without loops/recursion.
// Runtime: O(1)
// Space: O(1)
bool isPowerOfTwo(int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}

void proof_harness_isPowerOfTwo() {
    int n;
    __CPROVER_assume(n >= 0);
    bool expected_result = (n > 0) && ((n & (n - 1)) == 0);
    bool result = isPowerOfTwo(n);
    assert(result == expected_result);
}

int main() {
    return 0;
}

void proof_harness_main() {
    main();
}

void combined_proof_harness() {
    proof_harness_isPowerOfTwo();
    proof_harness_main();
}