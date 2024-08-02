

#include <assert.h>  
#include <errno.h>  
#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>   

unsigned int fib(int number)
{
    
    if (number <= 0)
    {
        fprintf(stderr, "Illegal Argument Is Passed!\n");
        exit(EXIT_FAILURE);
    }

    
    if (number == 1)
        return 0;

    if (number == 2)
        return 1;

    
    return fib(number - 1) + fib(number - 2);
}


int getInput(void)
{
    int num, excess_len;
    char buffer[3], *endPtr;

    while (1)
    {  
        printf("Please enter a valid number:");
        fgets(buffer, 3, stdin);  

        excess_len = 0;
        if (!(buffer[0] == '\n' ||
            buffer[1] == '\n' ||
            buffer[2] == '\n')) {
            while (getchar() != '\n') excess_len++;
        }

        num = strtol(buffer, &endPtr,
                     10);  

        
        if (  
            (excess_len > 0 || num > 48) ||
            
            (*endPtr != '\0' && *endPtr != '\n') ||
            
            endPtr == buffer)
        {
            continue;
        }

        break;
    }

    printf("\nEntered digit: %d (it might take sometime)\n", num);
    return num;
}


static void test()
{
    assert(fib(5) == 3);
    assert(fib(2) == 1);
    assert(fib(9) == 21);
}


int main()
{
    
    test();
    printf("Tests passed...\n");

    
    printf(
        "Enter n to find nth fibonacci element...\n"
        "Note: You would be asked to enter input until valid number ( less "
        "than or equal to 48 ) is entered.\n");

    int number = getInput();
    clock_t start, end;

    start = clock();
    printf("Fibonacci element %d is %u ", number, fib(number));
    end = clock();

    printf("in %.3f seconds.\n", ((double)(end - start)) / CLOCKS_PER_SEC );
    return 0;
}
