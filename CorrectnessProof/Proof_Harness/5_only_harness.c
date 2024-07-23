void proof_harness_longestPalindrome() {
    char *s;
    int len;
    __CPROVER_assume(len >= 0);
    s = (char *) malloc(len + 1);
    __CPROVER_assume(s != NULL);
    s[len] = '\0';
    for (int i = 0; i < len; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_longestPalindrome();
}

