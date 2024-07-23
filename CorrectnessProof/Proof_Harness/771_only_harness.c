void combined_proof_harness() {
    proof_harness_numJewelsInStones();
}

void proof_harness_numJewelsInStones() {
    char *j = (char *)malloc(500 * sizeof(char));
    __CPROVER_assume(j != NULL);
    char *s = (char *)malloc(500 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int expected_result;
    __CPROVER_assume(strlen(j) > 0);
    __CPROVER_assume(strlen(s) > 0);

    expected_result = numJewelsInStones(j, s);

    int actual_result = numJewelsInStones(j, s);
    assert(actual_result == expected_result);
    
    free(j);
    free(s);
}

