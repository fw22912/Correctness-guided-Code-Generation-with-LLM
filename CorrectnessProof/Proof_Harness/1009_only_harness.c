void proof_harness_main() {
    int n;
    __CPROVER_assume(n >= 0);

    int expected_result = bitwiseComplement(n);

    int actual_result = bitwiseComplement(n);

    assert(actual_result == expected_result);
}

void combined_proof_harness() {
    proof_harness_bitwiseComplement();
    proof_harness_main();
}

void proof_harness_bitwiseComplement() {
    int n;
    __CPROVER_assume(n >= 0);

    int expected_result = bitwiseComplement(n);

    int actual_result = bitwiseComplement(n);

    assert(actual_result == expected_result);
}

