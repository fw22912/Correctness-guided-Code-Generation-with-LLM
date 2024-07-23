void proof_harness_countAndSay() {
    int n;
    __CPROVER_assume(n >= 1);
    char *result = countAndSay(n);
    free(result);
}

void combined_proof_harness() {
    proof_harness_countAndSay();
}

