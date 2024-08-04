
int *sortArrayByParity(int *A, int ASize, int *returnSize)
{
    int *retArr = malloc(ASize * sizeof(int));
    int oddIndex = ASize - 1;
    int evenIndex = 0;
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++)
    {
        if (A[i] % 2 == 0)
        {
            retArr[evenIndex] = A[i];
            evenIndex++;
        }
        else
        {
            retArr[oddIndex] = A[i];
            oddIndex--;
        }
    }

    return retArr;
}
