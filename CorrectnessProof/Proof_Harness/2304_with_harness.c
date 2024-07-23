#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define min(x,y)(((x)<(y))?(x):(y))

// DP up -> down. We are going down from gridline to gridline
// and collect the minumum cost path.
// Runtime : O(gridSize*gridColSize*gridColSize)
// Space: O(gridColSize)
int minPathCost(int** grid, int gridSize, int* gridColSize, int** moveCost, int moveCostSize, int* moveCostColSize){
    int* dp = (int*)calloc(gridColSize[0], sizeof(int));
    int* newDp = (int*)calloc(gridColSize[0], sizeof(int));
    
    for(int i = 0; i < gridSize - 1; i++){
        int currGridColSize = gridColSize[i];
        for(int j = 0; j < currGridColSize; j++){
            newDp[j] = -1;
        }
        
        for(int j = 0; j < currGridColSize; j++){
            int currGridItem = grid[i][j];
            for(int z = 0; z < currGridColSize; z++){
                int currMoveCost = dp[j] + moveCost[currGridItem][z] + currGridItem;
                
                newDp[z] = (newDp[z] == -1) ? currMoveCost : min(newDp[z], currMoveCost);
            }
        }
        
        for(int j = 0; j < currGridColSize; j++){
            dp[j] = newDp[j];
        }
    }
    
    // Find minimum value.
    int minValue = dp[0] + grid[gridSize - 1][0];
    for(int j = 1; j < gridColSize[0]; j++){
        minValue = min(minValue, dp[j] + grid[gridSize - 1][j]);
    }
    
    // free resources
    free(dp);
    free(newDp);
    
    return minValue;
}

void proof_harness_minPathCost(){
    int gridSize;
    __CPROVER_assume(gridSize > 0);
    int* gridColSize = (int*)malloc(sizeof(int) * gridSize);
    __CPROVER_assume(gridColSize != NULL);
    int** grid = (int**)malloc(sizeof(int*) * gridSize);
    __CPROVER_assume(grid != NULL);
    for(int i = 0; i < gridSize; i++){
        __CPROVER_assume(gridColSize[i] > 0);
        grid[i] = (int*)malloc(sizeof(int) * gridColSize[i]);
        __CPROVER_assume(grid[i] != NULL);
        for(int j = 0; j < gridColSize[i]; j++){
            grid[i][j] = rand();
        }
    }
    
    int moveCostSize;
    __CPROVER_assume(moveCostSize > 0);
    int* moveCostColSize = (int*)malloc(sizeof(int) * moveCostSize);
    __CPROVER_assume(moveCostColSize != NULL);
    int** moveCost = (int**)malloc(sizeof(int*) * moveCostSize);
    __CPROVER_assume(moveCost != NULL);
    for(int i = 0; i < moveCostSize; i++){
        __CPROVER_assume(moveCostColSize[i] > 0);
        moveCost[i] = (int*)malloc(sizeof(int) * moveCostColSize[i]);
        __CPROVER_assume(moveCost[i] != NULL);
        for(int j = 0; j < moveCostColSize[i]; j++){
            moveCost[i][j] = rand();
        }
    }
    
    int result = minPathCost(grid, gridSize, gridColSize, moveCost, moveCostSize, moveCostColSize);
    
    for(int i = 0; i < gridSize; i++){
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);
    for(int i = 0; i < moveCostSize; i++){
        free(moveCost[i]);
    }
    free(moveCost);
    free(moveCostColSize);
}

void proof_harness_main(){
}

void combined_proof_harness(){
    proof_harness_minPathCost();
    proof_harness_main();
}