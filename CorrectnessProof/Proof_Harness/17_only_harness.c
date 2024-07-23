void combined_proof_harness() {
    proof_harness_get_letters();
    proof_harness_letterCombinations();
    proof_harness_main();
}

void proof_harness_get_letters() {
    char digit;
    __CPROVER_assume(digit >= '0' && digit <= '9');
    char *result = get_letters(digit);
    if (digit >= '2' && digit <= '9') {
        assert(strlen(result) > 0);
    }

void proof_harness_main() {
    char *digits = malloc(10);
    __CPROVER_assume(digits != NULL);
    int return_size;
    char **combs = letterCombinations(digits, &return_size);
    if (combs == NULL) {
        assert(return_size == 0);
    }

void proof_harness_letterCombinations() {
    char *digits = malloc(10);
    __CPROVER_assume(digits != NULL);
    int return_size;
    int digits_size = 0;
    char *cp = digits;
    while(*cp != '\0') {
        __CPROVER_assume(*cp >= '2' && *cp <= '9');
        digits_size++;
        cp++;
    }

