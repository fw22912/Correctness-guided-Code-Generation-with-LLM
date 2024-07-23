void proof_harness_uniquePathsWithObstacles() {
    int obstacleGridSize;
    int obstacleGridColSize;
    __CPROVER_assume(obstacleGridSize > 0 && obstacleGridSize <= 100);
    __CPROVER_assume(obstacleGridColSize > 0 && obstacleGridColSize <= 100);
    int** obstacleGrid = malloc(sizeof(int*) * obstacleGridSize);
    __CPROVER_assume(obstacleGrid != NULL);
    for (int i = 0; i < obstacleGridSize; i++) {
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize);
        __CPROVER_assume(obstacleGrid[i] != NULL);
        for (int j = 0; j < obstacleGridColSize; j++) {
            __CPROVER_assume(obstacleGrid[i][j] >= 0 && obstacleGrid[i][j] <= 1);
        }

void combined_proof_harness() {
    proof_harness_uniquePathsWithObstacles();
}

