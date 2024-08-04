
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


char is_prime(unsigned long n)
{
    for (unsigned long i = 2; i < sqrtl(n) + 1; i++)
        if (n % i == 0)
            return 0;

    return 1;
}


unsigned long long sum_of_primes(unsigned long N)
{
    unsigned long long sum = 2;

    for (long i = 3; i < N; i += 2) 
        if (is_prime(i))
            sum += i;

    return sum;
}


int main(int argc, char *argv[])
{
    unsigned long n = 100;

    if (argc == 2)         
        n = atol(argv[1]); 

    printf("%ld: %llu\n", n, sum_of_primes(n));

    return 0;
}