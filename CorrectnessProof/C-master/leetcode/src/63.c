

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                             int* obstacleGridColSize)
{
    if (obstacleGrid[obstacleGridSize - 1][*obstacleGridColSize - 1] == 1)
    {
        return 0;
    }
    int paths[obstacleGridSize][*obstacleGridColSize];
    for (int i = 0; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j])
            {
                paths[i][j] = 0;
            }
            else
            {
                paths[i][j] = (i == 0 && j == 0)
                                  ? 1
                                  : ((i == 0 ? 0 : paths[i - 1][j]) +
                                     (j == 0 ? 0 : paths[i][j - 1]));
            }
        }
    }
    return paths[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
