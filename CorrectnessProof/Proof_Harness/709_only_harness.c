void combined_proof_harness() {
    proof_harness_toLowerCase();
    proof_harness_main();
}

void proof_harness_toLowerCase() {
    char *str = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(str != NULL);
    
    size_t len = __CPROVER_nondet_uint();
    __CPROVER_assume(len < 100);
    
    for (size_t i = 0; i < len; i++) {
        str[i] = __CPROVER_nondet_char();
    }

void proof_harness_main() {
    main();
}

