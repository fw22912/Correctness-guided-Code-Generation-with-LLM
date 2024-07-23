void combined_proof_harness() {
    proof_harness_hammingWeight();
}

void proof_harness_hammingWeight() {
    uint32_t n;
    n = __CPROVER_input_uint32_t();
    int expected_result = hammingWeight(n);
    int actual_result = hammingWeight(n);
    assert(actual_result == expected_result);
}

