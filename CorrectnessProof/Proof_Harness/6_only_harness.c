void proof_harness_test() {
    test();
}

void proof_harness_testZigZag() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int numRows;
    __CPROVER_assume(numRows > 0);
    __CPROVER_assume(numRows <= 1024);
    char *expected = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(expected != NULL);
    testZigZag(s, numRows, expected);
    free(s);
    free(expected);
}

void proof_harness_main() {
    main();
}

void combined_proof_harness() {
    proof_harness_convert();
    proof_harness_testZigZag();
    proof_harness_test();
    proof_harness_main();
}

void proof_harness_convert() {
    char *in = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(in != NULL);
    uint16_t numRows;
    __CPROVER_assume(numRows > 0);
    __CPROVER_assume(numRows <= 1024);
    convert(in, numRows);
    free(in);
}

