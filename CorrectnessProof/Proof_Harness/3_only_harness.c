void proof_harness_lengthOfLongestSubstring() {
    char *str = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(str != NULL);

    int n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n < 1024);
    for (int i = 0; i < n; i++) {
        str[i] = (char)__CPROVER_nondet_int();
    }

void proof_harness_lengthOfLongestSubstring_brute_force() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n < 1024);
    for (int i = 0; i < n; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_lengthOfLongestSubstring();
    proof_harness_lengthOfLongestSubstring_brute_force();
}

