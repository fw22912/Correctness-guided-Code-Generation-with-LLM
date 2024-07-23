#include <assert.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    int index1 = 0;
    int index2 = 0;
    int v[nums1Size + nums2Size];
    int v_index = 0;

    while (index1 < nums1Size && index2 < nums2Size)
    {
        if (nums1[index1] <= nums2[index2])
        {
            v[v_index++] = nums1[index1++];
        }
        else
        {
            v[v_index++] = nums2[index2++];
        }
    }
    if (index1 < nums1Size)
    {
        while (index1 < nums1Size)
        {
            v[v_index++] = nums1[index1++];
        }
    }
    if (index2 < nums2Size)
    {
        while (index2 < nums2Size)
        {
            v[v_index++] = nums2[index2++];
        }
    }
    if (v_index == 1)
    {
        return v[0];
    }
    if (v_index % 2 == 0)
    {
        double n1, n2;
        n1 = v[v_index / 2];
        n2 = v[(v_index / 2) - 1];
        return (n1 + n2) / 2;
    }
    int new_index = (int)v_index / 2;
    int i = 0;
    return v[new_index];
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
    for (int i = 0; i < nums2Size; i++) {
        nums2[i] =  __CPROVER_nondet_int();
    }
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    free(nums1);
    free(nums2);
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
    for (int i = 0; i < nums2Size; i++) {
        nums2[i] =  __CPROVER_nondet_int();
    }
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    free(nums1);
    free(nums2);
}

void combined_proof_harness() {
    proof_harness_findMedianSortedArrays();
    proof_harness_main();
}