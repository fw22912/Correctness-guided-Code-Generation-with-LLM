
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    long n = 100;
    long long sum = 0;
    char *sieve = NULL;

    if (argc == 2)         
        n = atol(argv[1]); 

    
    sieve = calloc(n, sizeof(*sieve));
    if (!sieve)
    {
        perror("Unable to allocate memory!");
        return -1;
    }

    
    for (long i = 2; i < sqrtl(n); i++)
    {
        
        if (!sieve[i])
        {
            for (long j = i * i; j < n + 1; j += i)
            {
                sieve[j] = 1;
            }
            sum += i;
        }
    }

    for (long i = sqrtl(n) + 1; i < n; i++)
        if (!sieve[i])
            sum += i;

    free(sieve);

    printf("%ld: %lld\n", n, sum);

    return 0;
}
