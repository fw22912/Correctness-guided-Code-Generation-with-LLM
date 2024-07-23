void combined_proof_harness() {
    proof_harness_findTheDifference();
}

void proof_harness_findTheDifference() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char *t = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(t != NULL);
    int s_len = __CPROVER_nondet_int();
    __CPROVER_assume(s_len >= 0 && s_len < 100);
    int t_len = __CPROVER_nondet_int();
    __CPROVER_assume(t_len >= 0 && t_len < 100);
    for (int i = 0; i < s_len; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }

