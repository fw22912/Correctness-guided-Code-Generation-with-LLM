void proof_harness_main() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_numOfSubarrays();
    proof_harness_main();
}

void proof_harness_numOfSubarrays() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

