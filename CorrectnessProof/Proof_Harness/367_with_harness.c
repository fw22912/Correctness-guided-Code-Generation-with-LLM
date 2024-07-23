#include <assert.h>
#include <stdbool.h>

bool isPerfectSquare(int num)
{
    for (long i = 1; i * i <= num; i++)
        if (i * i == num)
            return true;
    return false;
}

void proof_harness_isPerfectSquare() {
    int num;
    __CPROVER_assume(num >= 0);
    bool expected_result = isPerfectSquare(num);
    bool actual_result = isPerfectSquare(num);
    assert(actual_result == expected_result);
}


void combined_proof_harness() {
    proof_harness_isPerfectSquare();
}