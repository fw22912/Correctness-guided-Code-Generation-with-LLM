int compare(const void* i, const void* j)
{
    return *((int*)i) - *((int*)j);
}




int maxIceCream(int* costs, int costsSize, int coins){
    qsort(costs, costsSize, sizeof(int), compare);

    int result = 0;
    int leftCoins = coins;
    for (int i = 0; i < costsSize; i++){
        if (costs[i] > leftCoins){
            break;
        }

        leftCoins -= costs[i];
        result++;
    }

    return result;
}
