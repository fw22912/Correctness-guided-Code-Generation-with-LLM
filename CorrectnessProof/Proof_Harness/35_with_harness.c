#include <assert.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target > nums[mid])
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
        else
            return mid;
    }
    return low;
}

/* Recursive version */
//int searchInsert(int *nums, int numsSize, int target)
//{
//    int idx = numsSize - 1;
//    if (numsSize > 0)
//    {
//        if (target > nums[idx])
//        {
//            return numsSize;
//        }
//        return searchInsert(nums, numsSize - 1, target);
//    }
//    return 0;
//}

void proof_harness_searchInsert() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    int target;
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0);
        __CPROVER_assume(nums[i] <= 100);
    }
    __CPROVER_assume(target >= 0);
    __CPROVER_assume(target <= 100);
    int expected_result = searchInsert(nums, numsSize, target);
    int actual_result = searchInsert(nums, numsSize, target);
    assert(expected_result == actual_result);
    free(nums);
}

void proof_harness_main() {
    int argc;
    __CPROVER_assume(argc >= 0);
    char **argv = (char **)malloc(sizeof(char *) * argc);
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        __CPROVER_assume(argv[i] != NULL);
    }
    main(argc, argv);
    free(argv);
}

void combined_proof_harness() {
    proof_harness_searchInsert();
    proof_harness_main();
}