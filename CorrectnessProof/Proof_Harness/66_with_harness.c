#include <assert.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }

    int *newdigit = (int *)malloc((digitsSize + 1) * sizeof(int));
    newdigit[0] = 1;
    for (int i = 1; i < (digitsSize + 1); i++)
    {
        newdigit[i] = digits[i - 1];
    }
    *returnSize = digitsSize + 1;
    return newdigit;
}

void proof_harness_plusOne() {
    int digitsSize;
    __CPROVER_assume(digitsSize > 0);
    int *digits = (int*)malloc(sizeof(int) * digitsSize);
    __CPROVER_assume(digits != NULL);
    for (int i = 0; i < digitsSize; i++) {
        __CPROVER_assume(digits[i] >= 0 && digits[i] <= 9);
    }
    int returnSize;
    int *ret = plusOne(digits, digitsSize, &returnSize);
    if (returnSize == digitsSize) {
        for (int i = 0; i < returnSize; i++) {
            assert(ret[i] >= 0 && ret[i] <= 9);
        }
    } else {
        assert(returnSize == digitsSize + 1);
        assert(ret[0] == 1);
        for (int i = 1; i < returnSize; i++) {
            assert(ret[i] >= 0 && ret[i] <= 9);
        }
    }
    free(digits);
    free(ret);
}

void proof_harness_main() {
    int digitsSize;
    __CPROVER_assume(digitsSize > 0);
    int *digits = (int*)malloc(sizeof(int) * digitsSize);
    __CPROVER_assume(digits != NULL);
    for (int i = 0; i < digitsSize; i++) {
        __CPROVER_assume(digits[i] >= 0 && digits[i] <= 9);
    }
    int returnSize;
    int *ret = plusOne(digits, digitsSize, &returnSize);
    free(digits);
    free(ret);
}


void combined_proof_harness() {
    proof_harness_plusOne();
    proof_harness_main();
}