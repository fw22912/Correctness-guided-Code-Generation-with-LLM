void combined_proof_harness() {
    proof_harness_detectCapitalUse();
    proof_harness_isAllUpper();
    proof_harness_detectCapitalUse();
}

void proof_harness_isAllUpper() {
    char *word = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL); 
    
    int len = __CPROVER_nondet_int(); 
    __CPROVER_assume(len >= 0 && len <= 100); 
    
    for (int i = 0; i < len; i++) {
        word[i] = __CPROVER_nondet_char(); 
    }

void proof_harness_detectCapitalUse() {
    char *word = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL); 
    
    int len = __CPROVER_nondet_int(); 
    __CPROVER_assume(len >= 0 && len <= 100); 
    
    for (int i = 0; i < len; i++) {
        word[i] = __CPROVER_nondet_char(); 
    }

