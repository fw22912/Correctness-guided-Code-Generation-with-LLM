#define min(a,b) (((a)<(b))?(a):(b))




int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int* dp = calloc(matrixSize, sizeof(int));

    for (int i = 0; i < matrixSize; i++){
        int* nextDp = calloc(matrixSize, sizeof(int));

        for (int j = 0; j < matrixSize; j++){
            nextDp[j] = dp[j] + matrix[i][j];

            
            if(j > 0){
                nextDp[j] = min(nextDp[j], dp[j - 1] + matrix[i][j]);
            }

            
            if (j < matrixSize - 1){
                nextDp[j] = min(nextDp[j], dp[j + 1] + matrix[i][j]);
            }
        }

        free(dp);
        dp = nextDp;
    }

    int result = dp[0];
    for (int j = 1; j < matrixSize; j++){
        result = min(result, dp[j]);
    }

    free(dp);
    return result;
}
