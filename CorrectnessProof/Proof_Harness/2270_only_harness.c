void proof_harness_main() {
    int argc = __CPROVER_nondet_int();
    char** argv = (char**)malloc(sizeof(char*) * argc);
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = (char*)malloc(sizeof(char) * 100);
        __CPROVER_assume(argv[i] != NULL);
    }

void proof_harness_waysToSplitArray() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_waysToSplitArray();
    proof_harness_main();
}

