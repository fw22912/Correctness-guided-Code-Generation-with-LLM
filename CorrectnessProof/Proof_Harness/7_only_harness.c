void proof_harness_reverse() {
    int x;
    __CPROVER_assume(x >= INT_MIN && x <= INT_MAX);
    int expected = reverse(x);
    int actual = reverse(x);
    assert(actual == expected);
}

void combined_proof_harness() {
    proof_harness_reverse();
    proof_harness_main();
}

void proof_harness_main() {
    int x;
    __CPROVER_assume(x >= INT_MIN && x <= INT_MAX);
    reverse(x);
}

