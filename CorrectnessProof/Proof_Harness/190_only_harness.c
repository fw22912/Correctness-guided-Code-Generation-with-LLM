void proof_harness_reverseBits() {
    uint32_t n;
    n = __CPROVER_input_uint32_t();
    uint32_t expected = reverseBits(n);
    uint32_t result = reverseBits(n);
    assert(result == expected);
}

void proof_harness_main() {
    uint32_t n = __CPROVER_input_uint32_t();
    reverseBits(n);
}

void combined_proof_harness() {
    proof_harness_reverseBits();
    proof_harness_main();
}

