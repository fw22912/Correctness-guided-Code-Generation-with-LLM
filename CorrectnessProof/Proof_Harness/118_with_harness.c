#include <assert.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int **ans = (int**)malloc(numRows*sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int)); 
   
   for (int i=0; i<numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        ans[i] = (int*)malloc((i+1)*sizeof(int));
    }
    
    ans[0][0] = 1;
    
    for (int i=1; i<numRows; i++) {
        ans[i][0] = 1;
        for (int j=1; j<i; j++) {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans[i][i] = 1;
    }
    return ans;
}

void proof_harness_generate() {
    int numRows;
    int returnSize;
    int *returnColumnSizes;
    int **ans;

    __CPROVER_assume(numRows >= 0);

    ans = generate(numRows, &returnSize, &returnColumnSizes);

    // Check returnSize
    assert(returnSize == numRows);

    // Check returnColumnSizes
    for (int i = 0; i < returnSize; i++) {
        assert(returnColumnSizes[i] == i + 1);
    }

    // Check the generated Pascal's Triangle
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                assert(ans[i][j] == 1);
            } else {
                assert(ans[i][j] == ans[i - 1][j - 1] + ans[i - 1][j]);
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void proof_harness_main() {
    int numRows = 5;
    int returnSize;
    int *returnColumnSizes;
    int **ans = generate(numRows, &returnSize, &returnColumnSizes);

    // Check returnSize
    assert(returnSize == numRows);

    // Check returnColumnSizes
    for (int i = 0; i < returnSize; i++) {
        assert(returnColumnSizes[i] == i + 1);
    }

    // Check the generated Pascal's Triangle
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                assert(ans[i][j] == 1);
            } else {
                assert(ans[i][j] == ans[i - 1][j - 1] + ans[i - 1][j]);
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void combined_proof_harness() {
    proof_harness_generate();
    proof_harness_main();
}