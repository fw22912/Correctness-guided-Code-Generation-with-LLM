void proof_harness_isPowerOfTwo() {
    int n;
    __CPROVER_assume(n >= 0);
    bool expected_result = (n > 0) && ((n & (n - 1)) == 0);
    bool result = isPowerOfTwo(n);
    assert(result == expected_result);
}

void combined_proof_harness() {
    proof_harness_isPowerOfTwo();
    proof_harness_main();
}

void proof_harness_main() {
    main();
}

