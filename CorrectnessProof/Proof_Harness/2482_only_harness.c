void combined_proof_harness(){
    proof_harness_onesMinusZeros();
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

