void combined_proof_harness() {
    proof_harness_isAnagram();
}

void proof_harness_isAnagram() {
    char *s = (char *)malloc(1000 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char *t = (char *)malloc(1000 * sizeof(char));
    __CPROVER_assume(t != NULL);
    __CPROVER_assume(strlen(s) <= 1000);
    __CPROVER_assume(strlen(t) <= 1000);

    for (int i = 0; i < strlen(s); i++) {
        __CPROVER_assume(s[i] >= 'a' && s[i] <= 'z');
    }

