#include <assert.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int colIndex = rowIndex + 1;
    int* ans = (int*) malloc(sizeof(int) * colIndex);
    for (int i = 0; i < colIndex; i++)
    {
        ans[i] = 1;
    }
    *returnSize = colIndex;
    
    for (int r = 2; r <= rowIndex; r++)
    {
        for (int c = r - 1; c > 0; c--)
        {
            ans[c] = ans[c] + ans[c-1];
        }
    }
    
    return ans;
}

void proof_harness_getRow() {
    int rowIndex;
    int returnSize;
    __CPROVER_assume(rowIndex >= 0);
    int* ret = getRow(rowIndex, &returnSize);
    
    // Assertions to check the correctness of the returned array
    assert(returnSize == rowIndex + 1);
    
    // Free the dynamically allocated memory
    free(ret);
}

void proof_harness_main() {
    int rowIndex;
    int returnSize;
    __CPROVER_assume(rowIndex >= 0);
    int* ret = getRow(rowIndex, &returnSize);
    
    // Assertions to check the correctness of the returned array
    assert(returnSize == rowIndex + 1);
    
    // Free the dynamically allocated memory
    free(ret);
}

void combined_proof_harness() {
    proof_harness_getRow();
    proof_harness_main();
}