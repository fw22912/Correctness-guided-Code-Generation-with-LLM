void proof_harness_numberOfWays() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

void proof_harness_numberOfWaysForChar() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char c;
    __CPROVER_assume(c == '0' || c == '1');

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

void combined_proof_harness() {
    proof_harness_numberOfWaysForChar();
    proof_harness_numberOfWays();
    proof_harness_main();
}

void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

