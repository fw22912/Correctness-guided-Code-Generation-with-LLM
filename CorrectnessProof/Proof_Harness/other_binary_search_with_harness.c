#include <stdio.h>
    #include <stdlib.h>
    #define len 5
    #include <assert.h>
    
    int binarySearch(int array[], int leng, int searchX)
    {
        int pos = -1, right, left, i = 0;
    
        left = 0;
        right = leng - 1;
    
        while (left <= right)
        {
            pos = left + (right - left) / 2;
            if (array[pos] == searchX)
            {
                return pos;
            }
            else if (array[pos] > searchX)
            {
                right = pos - 1;
            }
            else
            {
                left = pos + 1;
            }
        }
        return -1; /* not found */
    }
    
    int main(int argc, char *argv[])
    {
        int array[len] = {5, 8, 10, 14, 16};
    
        int position;
        position = binarySearch(array, len, 5);
    
        if (position < 0)
            printf("The number %d doesnt exist in array\n", 5);
        else
        {
            printf("The number %d exist in array at position : %d \n", 5, position);
        }
    
        return 0;
    }
    
    void proof_harness_binarySearch() {
        int array[len];
        int leng;
        int searchX;
        __CPROVER_assume(leng >= 0);
        __CPROVER_assume(leng <= 5);
        __CPROVER_assume(searchX >= 0);
        __CPROVER_assume(searchX <= 2147483647);
        for (int i = 0; i < len; i++) {
            __CPROVER_assume(array[i] >= 0);
            __CPROVER_assume(array[i] <= 2147483647);
        }
        int result = binarySearch(array, leng, searchX);
        if (result >= 0) {
            assert(array[result] == searchX);
        } else {
            int i;
            for (i = 0; i < leng; i++) {
                assert(array[i] != searchX);
            }
        }
    }