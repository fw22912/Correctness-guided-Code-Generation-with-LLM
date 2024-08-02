

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


void fib(unsigned long n, unsigned long *C, unsigned long *D)
{
    
    
    
    
    
    
    

    unsigned long a, b, c, d;

    if (n == 0)
    {
        C[0] = 0;
        if (D) 
            D[0] = 1;
        return;
    }

    fib(n >> 1, &c, &d); 

    a = c * ((d << 1) - c);
    b = c * c + d * d;
    if (n % 2 == 0) 
    {
        C[0] = a;
        if (D)
            D[0] = b;
        return;
    }

    
    C[0] = b;
    if (D) 
        D[0] = a + b;
    return;
}


int main(int argc, char *argv[])
{
    unsigned long number, result;

    setlocale(LC_NUMERIC, "");  

    
    if (argc == 2)
        number = atoi(argv[1]);
    else
    {
        printf("Enter the value of n(n starts from 0 ): ");
        scanf("%lu", &number);
    }

    fib(number, &result, NULL);

    printf("The nth term is : %'lu \n", result);

    return 0;
}
