void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    int sLen;
    __CPROVER_assume(sLen >= 0 && sLen <= 100);
    
    for (int i = 0; i < sLen; i++) {
        s[i] = (char)__CPROVER_choice_int(256);
    }

void combined_proof_harness() {
    proof_harness_countSegments();
    proof_harness_main();
}

void proof_harness_countSegments() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    int sLen;
    __CPROVER_assume(sLen >= 0 && sLen <= 100);
    
    for (int i = 0; i < sLen; i++) {
        s[i] = (char)__CPROVER_choice_int(256);
    }

