

#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 


void patienceSort(int *array, int length) {
    
    int* *piles = (int* *) malloc(sizeof(int*) * length);
    for (int i = 0; i < length; ++i) {
        piles[i] = malloc(sizeof(int) * length);
    }

    
    
    int *pileSizes = (int*) calloc(length,sizeof(int));

    
    
    piles[0][0] = array[0];
    int pileCount = 1;

    for (int i = 1; i < length; ++i) {
        
        int flag = 1;

        for (int j = 0; j < pileCount; ++j) {
            if(piles[j][pileSizes[j]] > array[i]) {
                
                piles[j][pileSizes[j] + 1] = array[i];
                pileSizes[j]++;
                flag--;
                break;
            }
        }

        if(flag) {
            
            piles[pileCount][0] = array[i];
            pileCount++;
        }
    }

    
    int min, minLocation;

    for (int i = 0; i < length; ++i) {
        
        
        
        
        for (int j = 0; j < pileCount; ++j) {
            if(pileSizes[j] < 0) {
                continue;
            }
            min = piles[j][pileSizes[j]];
            minLocation = j;
            break;
        }

        for (int j = 0; j < pileCount; ++j) {
            if(pileSizes[j] < 0) {
                continue;
            }
            if(piles[j][pileSizes[j]] < min) {
                min = piles[j][pileSizes[j]];
                minLocation = j;
            }
        }

        array[i] = min;
        pileSizes[minLocation]--;
    }

    
    free(pileSizes);
    for (int i = 0; i < length; ++i) {
        free(piles[i]);
    }
    free(piles);
}


void printArray(int *array,int length) {
    printf("Array:");
    for (int i = 0; i < length; ++i) {
        printf("%d",array[i]);
        if (i != length - 1) putchar(',');
    }
    putchar('\n');
}



void testArray(int *array,int length) {
    printf("Before sorting:\n");
    printArray(array,length);

    patienceSort(array,length);

    printf("After sorting:\n");
    printArray(array,length);

    for (int i = 0; i < length - 1; ++i) {
        assert(array[i] <= array[i + 1]);
    }
    printf("All assertions have passed!\n\n");
}


static void test() {
    int testArray1[] = {2,8,7,1,3,5,6,4};
    int testArray2[] = {2,2,5,1,3,5,6,4};
    int testArray3[] = {1,2,3,4,5,6,7,8};
    int testArray4[] = {8,7,6,5,4,3,2,1};

    testArray(testArray1,8);
    testArray(testArray2,8);
    testArray(testArray3,8);
    testArray(testArray4,8);

    printf("Testing successfully completed!\n");
}


int main() {
    test();  
    return 0;
}
