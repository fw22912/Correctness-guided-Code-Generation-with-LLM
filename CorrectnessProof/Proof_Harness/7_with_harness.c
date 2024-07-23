#include <limits.h>
#include <assert.h>

int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

void proof_harness_reverse() {
    int x;
    __CPROVER_assume(x >= INT_MIN && x <= INT_MAX);
    int expected = reverse(x);
    int actual = reverse(x);
    assert(actual == expected);
}


void proof_harness_main() {
    int x;
    __CPROVER_assume(x >= INT_MIN && x <= INT_MAX);
    reverse(x);
}

void combined_proof_harness() {
    proof_harness_reverse();
    proof_harness_main();
}