#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Calculating ones on each row and column.
// Runtime: O(n * m)
// Space: O(n + m)
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
    int n = gridSize;
    int m = gridColSize[0];

    int** result = malloc(gridSize * sizeof(int*));
    for (int i = 0; i < n; i++){
        result[i] = malloc(m * sizeof(int));
    }

    int* onesRows = calloc(n, sizeof(int));
    int* onesCols = calloc(m, sizeof(int));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                onesRows[i] += 1;
                onesCols[j] += 1;
            }
        }
    }

    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            result[i][j] = onesRows[i] + onesCols[j] - (m - onesRows[i]) - (n - onesCols[j]);
        }
    }

    free(onesRows);
    free(onesCols);

    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return result;
}


void proof_harness_onesMinusZeros(){
    int gridSize;
    int *gridColSize;
    int returnSize;
    int *returnColumnSizes;
    int **grid; 

    gridSize = __CPROVER_nondet_int();
    __CPROVER_assume(gridSize > 0);

    gridColSize = malloc(gridSize * sizeof(int));
    __CPROVER_assume(gridColSize != NULL);
    for (int i = 0; i < gridSize; i++) {
        gridColSize[i] = __CPROVER_nondet_int();
        __CPROVER_assume(gridColSize[i] > 0);
    }

    grid = malloc(gridSize * sizeof(int*));
    __CPROVER_assume(grid != NULL);
    for (int i = 0; i < gridSize; i++){
        grid[i] = malloc(gridColSize[i] * sizeof(int));
        __CPROVER_assume(grid[i] != NULL);
        for (int j = 0; j < gridColSize[i]; j++){
            grid[i][j] = __CPROVER_nondet_int();
        }
    }

    int **result = onesMinusZeros(grid, gridSize, gridColSize, &returnSize, &returnColumnSizes);
    
    assert(returnSize == gridSize);
    assert(returnColumnSizes == gridColSize);
    
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            int ones_row = 0;
            int ones_col = 0;
            for (int k = 0; k < gridSize; k++){
                if (grid[k][j] == 1){
                    ones_row++;
                }
            }
            for (int k = 0; k < gridColSize[i]; k++){
                if (grid[i][k] == 1){
                    ones_col++;
                }
            }
            assert(result[i][j] == ones_row + ones_col - (gridColSize[i] - ones_row) - (gridSize - ones_col));
        }
    }

    for (int i = 0; i < gridSize; i++){
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);
    free(returnColumnSizes);
    free(result);
}

void combined_proof_harness(){
    proof_harness_onesMinusZeros();
}

int main(){
    combined_proof_harness();
    return 0;
}