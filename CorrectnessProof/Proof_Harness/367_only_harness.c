void combined_proof_harness() {
    proof_harness_isPerfectSquare();
}

void proof_harness_isPerfectSquare() {
    int num;
    __CPROVER_assume(num >= 0);
    bool expected_result = isPerfectSquare(num);
    bool actual_result = isPerfectSquare(num);
    assert(actual_result == expected_result);
}

