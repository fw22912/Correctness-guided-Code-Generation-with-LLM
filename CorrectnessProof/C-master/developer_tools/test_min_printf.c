

#include "min_printf.h" 
#include <stdio.h> 


int main()
{
    
    min_printf(":%d: :%1.6d:\n", 12, 56);
    printf(":%d: :%1.6d:\n", 12, 56);

    printf("\n"); 

    
    min_printf(":%f: :%3.6f:\n", 104.5654, 43.766443332);
    printf(":%f: :%3.6f:\n", 104.5654, 43.766443332);

    printf("\n");

    
    min_printf(":%s: :%4.3s:\n", "Hello, World!", "Hello, World!");
    printf(":%s: :%4.3s:\n", "Hello, World!", "Hello, World!");

}
