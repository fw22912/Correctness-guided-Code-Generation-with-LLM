void proof_harness_main(){
}

void combined_proof_harness(){
    proof_harness_minPathCost();
    proof_harness_main();
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

