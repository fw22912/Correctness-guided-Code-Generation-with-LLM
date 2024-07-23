void proof_harness_charsCount(){
    char* word = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL);
    
    int* result = charsCount(word);
    
    free(word);
    free(result);
}

void proof_harness_closeStrings(){
    char* word1 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word1 != NULL);
    
    char* word2 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word2 != NULL);
    
    bool result = closeStrings(word1, word2);
    
    free(word1);
    free(word2);
}

void proof_harness_main(){
    char* word1 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word1 != NULL);
    
    char* word2 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word2 != NULL);
    
    int result = closeStrings(word1, word2);
    
    free(word1);
    free(word2);
}

void proof_harness_diff(){
    int i;
    int j;

    int* p_i = &i;
    int* p_j = &j;
    int result = diff(p_i, p_j);
    
}

void combined_proof_harness(){
    proof_harness_charsCount();
    proof_harness_diff();
    proof_harness_closeStrings();
    proof_harness_main();
}

