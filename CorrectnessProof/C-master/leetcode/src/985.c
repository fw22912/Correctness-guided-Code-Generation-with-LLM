


int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int summ = 0;
    int* result = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for(int i = 0; i < numsSize; i++){
        if (nums[i] % 2 == 0) {
            summ += nums[i];
        }
    }
    
    for(int i = 0; i < queriesSize; i++){
        int* query = queries[i];
        int val = query[0];
        int index = query[1];
        
        
        if (nums[index] % 2 == 0) {
            summ -= nums[index];
        }

        
        nums[index] += val;

        
        if (nums[index] % 2 == 0) {
            summ += nums[index];
        }
        
        result[i] = summ;
    }
    
    return result;
}
