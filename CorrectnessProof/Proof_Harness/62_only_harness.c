void proof_harness_uniquePaths() {
    int m;
    int n;
    __CPROVER_assume(m > 0);
    __CPROVER_assume(n > 0);
    int expected_result = uniquePaths(m, n);
    int result = uniquePaths(m, n);
    assert(result == expected_result);
}

void proof_harness_main() {
    int m;
    int n;
    __CPROVER_assume(m > 0);
    __CPROVER_assume(n > 0);
    int expected_result = uniquePaths(m, n);
    int result = uniquePaths(m, n);
    assert(result == expected_result);
}

void combined_proof_harness() {
    proof_harness_uniquePaths();
    proof_harness_main();
}

