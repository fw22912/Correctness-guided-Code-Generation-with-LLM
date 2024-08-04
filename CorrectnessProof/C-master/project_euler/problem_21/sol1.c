
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned long sum_of_divisors(unsigned int N)
{
    unsigned long sum = 1 + N; 
    
    for (unsigned int i = 2; i * i < N; i++)
    {
        if ((N % i) != 0)
            
            continue;

        
        
        

        sum += i + (N / i);
    }
    
    
    
    return sum;
}


int main(int argc, char **argv)
{
    unsigned long sum = 0;
    unsigned int MAX_N = 500;
    if (argc == 2)
        MAX_N = atoi(argv[1]);

    
    char *flags = (char *)calloc(MAX_N, sizeof(char));

    clock_t start_time = clock();
    int i;
    
    for (i = 10; i < MAX_N; i++)
    {
        if (flags[i] != 0)
            
            continue;

        unsigned int b = sum_of_divisors(i);
        if (b >= MAX_N)
            flags[i] = -1;
        else if (flags[b] == -1)
            continue;

        unsigned int c = sum_of_divisors(b);
        if (c == i && b != i)
        {
            
            flags[b] = 1;
            flags[i] = 1;
            sum += b + i;
#ifdef DEBUG
            printf("Amicable: %4d : %4d\n", i, b);
#endif
        }
        else
        {
            flags[i] = -1;
            if (b < MAX_N)
                flags[b] = -1;
        }
    }

    clock_t end_time = clock();

    printf("\nTime taken: %.4g millisecond\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf("Sum of all numbers = %lu\n", sum);

    free(flags);
    return 0;
}
