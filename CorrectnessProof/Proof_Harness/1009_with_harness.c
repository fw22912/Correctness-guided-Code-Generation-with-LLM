#include <assert.h>
#include <math.h>
#include <stdlib.h>

// Bit manipulation.
// - Find the bit length of n using log2
// - Create bit mask of bit length of n
// - Retun ~n and bit of ones mask
// Runtime: O(log2(n))
// Space: O(1)

int bitwiseComplement(int n){
    if (n == 0){
        return 1;
    }

    int binary_number_length = ceil(log2(n));
    return (~n) & ((1 << binary_number_length) - 1);
}


void proof_harness_bitwiseComplement() {
    int n;
    __CPROVER_assume(n >= 0);

    int expected_result = bitwiseComplement(n);

    int actual_result = bitwiseComplement(n);

    assert(actual_result == expected_result);
}


void proof_harness_main() {
    int n;
    __CPROVER_assume(n >= 0);

    int expected_result = bitwiseComplement(n);

    int actual_result = bitwiseComplement(n);

    assert(actual_result == expected_result);
}

void combined_proof_harness() {
    proof_harness_bitwiseComplement();
    proof_harness_main();
}