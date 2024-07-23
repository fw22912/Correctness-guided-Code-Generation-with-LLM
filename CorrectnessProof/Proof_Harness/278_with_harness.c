#include <assert.h>
#include <stdbool.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

void proof_harness_firstBadVersion() {
    int n;
    __CPROVER_assume(n > 0);
    int result = firstBadVersion(n);
    __CPROVER_assume(result >= 1 && result <= n);
    __CPROVER_assume(isBadVersion(result));
    __CPROVER_assume(!isBadVersion(result - 1));
}

void proof_harness_main() {
    int n;
    __CPROVER_assume(n > 0);
    int result = firstBadVersion(n);
    __CPROVER_assume(result >= 1 && result <= n);
    __CPROVER_assume(isBadVersion(result));
    __CPROVER_assume(!isBadVersion(result - 1));
}

void combined_proof_harness() {
    proof_harness_firstBadVersion();
    proof_harness_main();
}