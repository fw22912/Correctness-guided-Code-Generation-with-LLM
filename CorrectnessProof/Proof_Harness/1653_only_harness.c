void combined_proof_harness() {
    proof_harness_minimumDeletions();
}

void proof_harness_minimumDeletions() {
    char *s = malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int len = __CPROVER_nondet_int();
    __CPROVER_assume(len >= 0 && len < 100);
    for (int i = 0; i < len; i++) {
        s[i] = __CPROVER_nondet_char();
        __CPROVER_assume(s[i] == 'a' || s[i] == 'b');
    }

