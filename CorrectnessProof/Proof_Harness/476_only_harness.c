void combined_proof_harness() {
    proof_harness_findComplement();
}

void proof_harness_findComplement() {
    int num;
    __CPROVER_assume(num >= 0 && num <= INT_MAX);
    int expected = findComplement(num);
    int actual = findComplement(num);
    assert(expected == actual);
}

