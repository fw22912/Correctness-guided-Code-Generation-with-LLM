void proof_harness_main() {
    int numRows = 5;
    int returnSize;
    int *returnColumnSizes;
    int **ans = generate(numRows, &returnSize, &returnColumnSizes);

    // Check returnSize
    assert(returnSize == numRows);

    // Check returnColumnSizes
    for (int i = 0; i < returnSize; i++) {
        assert(returnColumnSizes[i] == i + 1);
    }

void proof_harness_generate() {
    int numRows;
    int returnSize;
    int *returnColumnSizes;
    int **ans;

    __CPROVER_assume(numRows >= 0);

    ans = generate(numRows, &returnSize, &returnColumnSizes);

    // Check returnSize
    assert(returnSize == numRows);

    // Check returnColumnSizes
    for (int i = 0; i < returnSize; i++) {
        assert(returnColumnSizes[i] == i + 1);
    }

void combined_proof_harness() {
    proof_harness_generate();
    proof_harness_main();
}

