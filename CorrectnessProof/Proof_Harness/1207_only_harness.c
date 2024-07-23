void combined_proof_harness() {
    proof_harness_uniqueOccurrences();
    proof_harness_main();
}

void proof_harness_uniqueOccurrences() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL);

    for (int i = 0; i < arrSize; i++) {
        __CPROVER_assume(arr[i] >= -MAP_SIZE / 2 && arr[i] <= MAP_SIZE / 2 - 1);
    }

void proof_harness_main() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL);

    for (int i = 0; i < arrSize; i++) {
        __CPROVER_assume(arr[i] >= -MAP_SIZE / 2 && arr[i] <= MAP_SIZE / 2 - 1);
    }

