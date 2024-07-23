void combined_proof_harness() {
    proof_harness_findMedianSortedArrays();
    proof_harness_main();
}

void proof_harness_main() {
    int nums1Size;
    int nums2Size;
    __CPROVER_assume(nums1Size >= 0);
    __CPROVER_assume(nums2Size >= 0);
    int *nums1 = (int*)malloc(sizeof(int) * nums1Size);
    __CPROVER_assume(nums1 != NULL);
    int *nums2 = (int*)malloc(sizeof(int) * nums2Size);
    __CPROVER_assume(nums2 != NULL);
    for (int i = 0; i < nums1Size; i++) {
        nums1[i] =  __CPROVER_nondet_int();
    }

void proof_harness_findMedianSortedArrays() {
    int nums1Size;
    int nums2Size;
    __CPROVER_assume(nums1Size >= 0);
    __CPROVER_assume(nums2Size >= 0);
    int *nums1 = (int*)malloc(sizeof(int) * nums1Size);
    __CPROVER_assume(nums1 != NULL);
    int *nums2 = (int*)malloc(sizeof(int) * nums2Size);
    __CPROVER_assume(nums2 != NULL);
    for (int i = 0; i < nums1Size; i++) {
        nums1[i] =  __CPROVER_nondet_int();
    }

