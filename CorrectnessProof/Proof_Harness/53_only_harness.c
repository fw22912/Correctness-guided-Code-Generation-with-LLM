void proof_harness_maxSubArray() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }

void combined_proof_harness() {
    proof_harness_maxcmp();
    proof_harness_maxSubArray();
    proof_harness_main();
}

void proof_harness_maxcmp() {
    int a = rand();
    int b = rand();
    int expected_result = a >= b ? a : b;

    int result = maxcmp(a, b);
    assert(result == expected_result);
}

void proof_harness_main() {
    int numsSize = 5;
    int nums[5] = {1, -2, 3, -4, 5}

