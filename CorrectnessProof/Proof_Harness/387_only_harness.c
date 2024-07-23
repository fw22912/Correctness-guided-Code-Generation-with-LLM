void proof_harness_firstUniqChar() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int expected_result;
    
    __CPROVER_assume(strlen(s) >= 0);
    
    expected_result = firstUniqChar(s);
    free(s);
}

void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    __CPROVER_assume(strlen(s) >= 0);
    
    firstUniqChar(s);
    free(s);
}

void combined_proof_harness() {
    proof_harness_firstUniqChar();
    proof_harness_main();
}

