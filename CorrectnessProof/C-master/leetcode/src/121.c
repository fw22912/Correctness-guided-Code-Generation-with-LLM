int maxcmp(int a, int b) { return (a >= b) ? a : b; }


int maxProfit(int *prices, int pricesSize)
{
    
    int maxCur = 0, maxSoFar = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        maxCur = maxcmp(0, maxCur + prices[i] - prices[i - 1]);
        maxSoFar = maxcmp(maxSoFar, maxCur);
    }
    return maxSoFar;
}
