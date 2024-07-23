void combined_proof_harness() {
    proof_harness_duplicateZeros();
}

void proof_harness_duplicateZeros() {
    int arrSize;
    __CPROVER_assume(arrSize > 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int(); 
    }

