

#include <stdlib.h>   
#include <assert.h>   
#include <stdbool.h>  

#define MAX 20


void bubble_sort(int* array_sort)
{
	bool is_sorted = false;

    
    while (!is_sorted)
    {
		is_sorted = true;

        
        for (int i = 0; i < MAX - 1; i++)
        {
            
            if (array_sort[i] > array_sort[i + 1])
            {
                
                int change_place = array_sort[i];
                array_sort[i] = array_sort[i + 1];
                array_sort[i + 1] = change_place;
                
                is_sorted = false;
            }
        }
    }
}


static void test() {
    
	int array_sort[MAX] = {0};

    
    for (int i = 0; i < MAX; i++)
    {
        array_sort[i] = rand() % 101;
    }

    
    bubble_sort(array_sort);

    	
    for (int i = 0; i < MAX - 1; i++)
    {
        assert(array_sort[i] <= array_sort[i+1]);
    }
}


int main()
{
    test();  
    return 0;
}
