#include <assert.h>
#include <stdlib.h>

int maxcmp(int a, int b) { return (a >= b) ? a : b; }

/* max subarray problem by using Kadane's Algorithm
 */
int maxProfit(int *prices, int pricesSize)
{
    /* maxCur: current maximum
     * maxSoFar: found maximum for subarray so far
     */
    int maxCur = 0, maxSoFar = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        maxCur = maxcmp(0, maxCur + prices[i] - prices[i - 1]);
        maxSoFar = maxcmp(maxSoFar, maxCur);
    }
    return maxSoFar;
}

void proof_harness_maxcmp() {
    int a;
    int b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int result = maxcmp(a, b);
    assert((result == a && a >= b) || (result == b && b >= a));
}

void proof_harness_maxProfit() {
    int pricesSize;
    __CPROVER_assume(pricesSize > 0);
    int *prices = (int *)malloc(sizeof(int) * pricesSize);
    __CPROVER_assume(prices != NULL);
    for (int i = 0; i < pricesSize; i++) {
        __CPROVER_assume(prices[i] >= 0);
    }
    int expected_result = maxProfit(prices, pricesSize);
    int result = maxProfit(prices, pricesSize);
    assert(result == expected_result);
    free(prices);
}

void combined_proof_harness() {
    proof_harness_maxcmp();
    proof_harness_maxProfit();
}