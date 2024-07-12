#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define len 5

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
    __CPROVER_assume(leng <= len);
    for (int i = 0; i < len; i++) {
        array[i] = rand();
    }
    searchX = rand();
    int result = binarySearch(array, leng, searchX);
    int expected_result = -1;
    for (int i = 0; i < leng; i++) {
        if (array[i] == searchX) {
            expected_result = i;
            break;
        }
    }
    assert(result == expected_result);
}