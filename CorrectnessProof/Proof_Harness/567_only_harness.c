void proof_harness_countCharsForStringSlice() {
    int length;
    int sign;
    __CPROVER_assume(length >= 0);
    __CPROVER_assume(sign >= -128);
    __CPROVER_assume(sign <= 127);
    char* s = malloc(length);
    __CPROVER_assume(s != NULL);
    int* charsCounter = malloc(EnglishLettersNumber * sizeof(int));
    __CPROVER_assume(charsCounter != NULL);
    for (int i = 0; i < EnglishLettersNumber; i++) {
        charsCounter[i] = 0;
    }

void combined_proof_harness() {
    proof_harness_countCharsForStringSlice();
    proof_harness_checkInclusion();
}

void proof_harness_checkInclusion() {
    char* s1 = malloc(100);
    __CPROVER_assume(s1 != NULL);
    char* s2 = malloc(100);
    __CPROVER_assume(s2 != NULL);
    bool result = checkInclusion(s1, s2);
    free(s1);
    free(s2);
}

