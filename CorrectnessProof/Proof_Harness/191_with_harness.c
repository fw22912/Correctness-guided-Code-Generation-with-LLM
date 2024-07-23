#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

int hammingWeight(uint32_t n)
{
    int TotalBits = 32;
    int i, weight = 0;
    for (i = 0; i < TotalBits; i++)
    {
        if (n &
            (UINT32_C(1)
             << i))  // if the bit on the ith position of 32 bit input is 1,
                     // then proceed Further note the use of UINT32_C to
                     // convert 1 to unsigned 32 bit int, as just 1 is treated
                     // as int which cannot be shifted left more than 30 times
            weight += 1;
    }
    return weight;
}

void proof_harness_hammingWeight() {
    uint32_t n;
    n = __CPROVER_input_uint32_t();
    int expected_result = hammingWeight(n);
    int actual_result = hammingWeight(n);
    assert(actual_result == expected_result);
}


void combined_proof_harness() {
    proof_harness_hammingWeight();
}

int main() {
    combined_proof_harness();
    return 0;
}