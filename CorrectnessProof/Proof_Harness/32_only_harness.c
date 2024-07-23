void proof_harness_longestValidParentheses(){
    char* s;

    s = malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);

    longestValidParentheses(s);

    free(s);
}

void proof_harness_getEndValidIndexFromDp(){
    int index;
    int lenS;
    char* s;
    int* dp;

    s = malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    dp = malloc(1024 * sizeof(int));
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(index < 1024);
    __CPROVER_assume(lenS >= 0);
    __CPROVER_assume(lenS < 1024);

    getEndValidIndexFromDp(dp, s, index, lenS);

    free(s);
    free(dp);
}

void proof_harness_getEndValidIndex(){
    int index;
    int lenS;
    char* s;
    int* dp;

    s = malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    dp = malloc(1024 * sizeof(int));
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(index < 1024);
    __CPROVER_assume(lenS >= 0);
    __CPROVER_assume(lenS < 1024);

    getEndValidIndex(dp, s, index, lenS);

    free(s);
    free(dp);
}

void combined_proof_harness(){
    proof_harness_getEndValidIndexFromDp();
    proof_harness_getEndValidIndex();
    proof_harness_longestValidParentheses();
    proof_harness_main();
}

void proof_harness_main(){
    char* s;

    s = malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);

    longestValidParentheses(s);

    free(s);
}

