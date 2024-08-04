
#include <assert.h>    
#include <inttypes.h>  
#include <stdio.h>     

#define ELEMENT -10

int64_t binary_search(const int64_t* arr, const uint16_t l_index, const uint16_t r_index, const int64_t n); 
int64_t exponential_search(const int64_t* arr, const uint16_t length, const int64_t n); 
static void test(); 


int64_t exponential_search(const int64_t* arr, const uint16_t length, const int64_t n) 
{
    if ( length == 0 ) { return -1; }
    
    uint32_t upper_bound = 1;
    while ( upper_bound <= length && arr[upper_bound] < n ) { upper_bound = upper_bound * 2; }
    
    uint16_t lower_bound = upper_bound/2;
    if ( upper_bound > length ) { upper_bound = length; }
    
    return binary_search(arr, lower_bound, upper_bound, n);
}


int64_t binary_search(const int64_t* arr, const uint16_t l_index, const uint16_t r_index, const int64_t n) 
{
    
    uint16_t middle_index = l_index + ( r_index - l_index ) / 2;
    
    if ( l_index > r_index ) { return -1; }
    if ( arr[middle_index] == n ) { return middle_index; }
    
    if ( arr[middle_index] > n ) { return binary_search(arr, l_index, middle_index-1, n); } 
    return binary_search(arr, middle_index+1, r_index, n); 
}


int main() 
{
    test();  
    return 0;
}


static void test()
{
    
    int64_t arr_empty[] = { 0 };
    assert(exponential_search(arr_empty, 0, 10) == -1);
    
    int64_t arr_found[] = {1, 2, 3};
    assert(exponential_search(arr_found, 3, 10) == -1);
    
    int64_t arr_one[] = {1};
    assert(exponential_search(arr_found, 1, 1) == 0);
    
    int64_t arr_first_2[] = {1, 2};
    assert(exponential_search(arr_first_2, 2, 1) == 0);
    
    int64_t arr_last_2[] = {1, 2};
    assert(exponential_search(arr_last_2, 2, 2) == 1);
    
    int64_t arr_first_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_first_n, 5, -1) == 0);
    
    int64_t arr_last_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_last_n, 5, 8) == 4);
    
    int64_t arr_middle[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_middle, 5, 6) == 3);

    printf("All tests have successfully passed!\n");
}
