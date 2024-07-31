
 
#include <assert.h>   
#include <inttypes.h> 
#include <stdio.h>    


uint32_t duplicateNumber(const uint32_t *in_arr, size_t n)
{
    if (n <= 1) {  
        return -1;
    }
    uint32_t tortoise = in_arr[0];  
                                    
    uint32_t hare = in_arr[0];  
    do {                                   
        tortoise = in_arr[tortoise];       
        hare = in_arr[in_arr[hare]];       
    } while (tortoise != hare);
    tortoise = in_arr[0];
    while (tortoise != hare) {             
        tortoise = in_arr[tortoise];
        hare = in_arr[hare];
    }
    return tortoise;
}


static void test()
{
    uint32_t arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610}; 
    size_t n = sizeof(arr) / sizeof(int);

    printf("1st test... ");
    uint32_t index = duplicateNumber(arr, n); 
    assert(index == 1); 
    printf("passed\n");
}


int main()
{
    test();  
    return 0;
}
