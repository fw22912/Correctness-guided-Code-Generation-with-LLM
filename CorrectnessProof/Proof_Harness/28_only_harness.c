void proof_harness_fill_overlap() {
    char *needle = (char*)malloc(1024 * sizeof(char));
    __CPROVER_assume(needle != NULL);
    int len_needle;
    int *overlap = (int*)malloc(1024 * sizeof(int));
    __CPROVER_assume(overlap != NULL);
    
    __CPROVER_assume(strlen(needle) >= 0 && strlen(needle) <= 1023);
    len_needle = strlen(needle);
    fill_overlap(needle, len_needle, overlap);
    free(needle);
    free(overlap);
}

void combined_proof_harness() {
    proof_harness_strStr();
    proof_harness_fill_overlap();
}

void proof_harness_strStr() {
    char *haystack = (char*)malloc(1024 * sizeof(char));
    __CPROVER_assume(haystack != NULL);
    char *needle = (char*)malloc(1024 * sizeof(char));
    __CPROVER_assume(needle != NULL);
    
    int ret;
    
    __CPROVER_assume(strlen(haystack) >= 0 && strlen(haystack) <= 1023);
    __CPROVER_assume(strlen(needle) >= 0 && strlen(needle) <= 1023);
    ret = strStr(haystack, needle);
    free(haystack);
    free(needle);
}

