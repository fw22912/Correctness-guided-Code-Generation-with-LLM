void combined_proof_harness() {
    proof_harness_arrayPairSum();
    proof_harness_main();
}

void proof_harness_arrayPairSum() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }

