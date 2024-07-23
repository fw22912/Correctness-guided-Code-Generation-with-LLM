void combined_proof_harness() {
    proof_harness_romanToInt();
}

void proof_harness_romanToInt() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int i = 0;
    while (i < 100) {
        s[i] = '\0';
        i++;
    }

