void proof_harness_check() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_check();
    proof_harness_main();
}

