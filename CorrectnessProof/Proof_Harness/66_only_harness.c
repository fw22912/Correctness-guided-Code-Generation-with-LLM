void proof_harness_plusOne() {
    int digitsSize;
    __CPROVER_assume(digitsSize > 0);
    int *digits = (int*)malloc(sizeof(int) * digitsSize);
    __CPROVER_assume(digits != NULL);
    for (int i = 0; i < digitsSize; i++) {
        __CPROVER_assume(digits[i] >= 0 && digits[i] <= 9);
    }

void combined_proof_harness() {
    proof_harness_plusOne();
    proof_harness_main();
}

void proof_harness_main() {
    int digitsSize;
    __CPROVER_assume(digitsSize > 0);
    int *digits = (int*)malloc(sizeof(int) * digitsSize);
    __CPROVER_assume(digits != NULL);
    for (int i = 0; i < digitsSize; i++) {
        __CPROVER_assume(digits[i] >= 0 && digits[i] <= 9);
    }

