






int* minOperations(char* boxes, int* returnSize){
    int leftOnes = 0;
    int leftCommonDistance = 0;
    
    int rightOnes = 0;
    int rightCommonDistance = 0;
    
    int boxesLength = strlen(boxes);

    *returnSize = boxesLength;
    int* result = malloc(boxesLength * sizeof(int));
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes += 1;
            rightCommonDistance += i;
        }
    }
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes -= 1;
            leftOnes += 1;
        }
        
        result[i] = rightCommonDistance + leftCommonDistance;
        rightCommonDistance -= rightOnes;
        leftCommonDistance += leftOnes;
    }

    return result;
}
