void combined_proof_harness() {
    proof_harness_maxcmp();
    proof_harness_maxProfit();
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

