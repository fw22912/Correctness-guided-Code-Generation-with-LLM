void combined_proof_harness() {
    proof_harness_firstBadVersion();
    proof_harness_main();
}

void proof_harness_main() {
    int n;
    __CPROVER_assume(n > 0);
    int result = firstBadVersion(n);
    __CPROVER_assume(result >= 1 && result <= n);
    __CPROVER_assume(isBadVersion(result));
    __CPROVER_assume(!isBadVersion(result - 1));
}

void proof_harness_firstBadVersion() {
    int n;
    __CPROVER_assume(n > 0);
    int result = firstBadVersion(n);
    __CPROVER_assume(result >= 1 && result <= n);
    __CPROVER_assume(isBadVersion(result));
    __CPROVER_assume(!isBadVersion(result - 1));
}

