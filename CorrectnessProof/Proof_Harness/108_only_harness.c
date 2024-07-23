void proof_harness_convertBST() {
    int *nums = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(nums != NULL);
    int left;
    int right;
    __CPROVER_assume(left >= 0);
    __CPROVER_assume(right >= 0);
    __CPROVER_assume(left <= right);
    __CPROVER_assume(right < 10);
    struct TreeNode *ret_val = convertBST(nums, left, right);
    free(nums);
}

void proof_harness_sortedArrayToBST() {
    int *nums = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(nums != NULL);
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    __CPROVER_assume(numsSize <= 10);
    struct TreeNode *ret_val = sortedArrayToBST(nums, numsSize);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_convertBST();
    proof_harness_sortedArrayToBST();
}

