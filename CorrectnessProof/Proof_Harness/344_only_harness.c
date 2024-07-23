void combined_proof_harness() {
    proof_harness_reverseString();
}

void proof_harness_reverseString() {
    int sSize;
    __CPROVER_assume(sSize >= 0);
    char *s = (char *)malloc(sizeof(char) * sSize);
    __CPROVER_assume(s != NULL); 
    
    for (int i = 0; i < sSize; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }

