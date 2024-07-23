void combined_proof_harness() {
    proof_harness_equalSubstrings();
    proof_harness_longestDecompositionDpCached();
    proof_harness_longestDecompositionDp();
    proof_harness_longestDecomposition();
    proof_harness_main();
}

void proof_harness_longestDecomposition() {
    char *text = NULL;
    __CPROVER_assume(text != NULL);
    int expected_result = longestDecomposition(text);
    int actual_result = longestDecomposition(text);
    assert(actual_result == expected_result);
}

void proof_harness_equalSubstrings() {
    char *text = NULL;
    int firstIndex;
    int secondIndex;
    int length;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(firstIndex >= 0);
    __CPROVER_assume(secondIndex >= 0);
    __CPROVER_assume(length >= 0);
    __CPROVER_assume(firstIndex + length <= strlen(text));
    __CPROVER_assume(secondIndex + length <= strlen(text));
    bool expected_result = equalSubstrings(text, firstIndex, secondIndex, length);
    bool actual_result = equalSubstrings(text, firstIndex, secondIndex, length);
    assert(actual_result == expected_result);
}

void proof_harness_longestDecompositionDp() {
    char *text = NULL;
    int textLen;
    int index;
    int *dp = NULL;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(textLen >= 0);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index < textLen);
    int expected_result = longestDecompositionDp(text, textLen, index, dp);
    int actual_result = longestDecompositionDp(text, textLen, index, dp);
    assert(actual_result == expected_result);
}

void proof_harness_main() {
    char *text = NULL;
    __CPROVER_assume(text != NULL);
    int expected_result = longestDecomposition(text);
    int actual_result = longestDecomposition(text);
    assert(actual_result == expected_result);
}

void proof_harness_longestDecompositionDpCached() {
    char *text = NULL;
    int textLen;
    int index;
    int *dp = NULL;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(textLen >= 0);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index < textLen);
    int expected_result = longestDecompositionDpCached(text, textLen, index, dp);
    int actual_result = longestDecompositionDpCached(text, textLen, index, dp);
    assert(actual_result == expected_result);
}

