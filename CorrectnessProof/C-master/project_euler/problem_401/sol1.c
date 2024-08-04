
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define MOD_LIMIT (uint64_t)1e9 
#define MAX_LENGTH 5000         


char is_in(uint64_t N, uint64_t *D, uint64_t L)
{
    uint64_t i;
    for (i = 0; i < L; i++)
    {
        if (D[i] == N)
        {
            return 1;
        }
    }
    return 0;
}


uint64_t get_divisors(uint64_t N, uint64_t *D)
{
    uint64_t q, r;
    int64_t i, num = 0;

    if (N == 1)
    {
        D[0] = 1;
        return 1;
    }

    
    
    for (i = 1; i * i <= N + 1; i++)
    {
        r = N % i;  

        
        if (r == 0)
        {
            q = N / i;
            if (!is_in(i, D, num))  
            {
                D[num] = i;
                num++;
            }
            if (!is_in(q, D, num))  
            {
                D[num] = q;
                num++;
            }
        }

        if (num == MAX_LENGTH)
        {  
            D = (uint64_t *)realloc(D, MAX_LENGTH * sizeof(uint64_t) << 1);
        }
    }
    return num;
}


uint64_t sigma2(uint64_t N)
{
    uint64_t sum = 0, L;
    int64_t i;
    uint64_t *D = (uint64_t *)malloc(MAX_LENGTH * sizeof(uint64_t));

    L = get_divisors(N, D);
    for (i = 1; i < L; i++)
    {
        uint64_t DD = (D[i] * D[i]) % MOD_LIMIT;
        sum += DD;
    }

    free(D);
    return sum % MOD_LIMIT;
}


uint64_t sigma(uint64_t N)
{
    uint64_t s, sum = 0;
    int64_t i;

#ifdef _OPENMP

#pragma omp parallel for reduction(+ : sum)
#endif
    for (i = 0; i <= N; i++)
    {
        s = sigma2(i);
        sum += s;
    }
    return sum % MOD_LIMIT;
}


int main(int argc, char **argv)
{
    uint64_t N = 1000;

    if (argc == 2)
    {
        N = strtoll(argv[1], NULL, 10);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Wrong number of input arguments!\n");
        printf("Usage:\t ./sol1.c [N=1000]");
        return -1;
    }

    clock_t start_time = clock();
    uint64_t result = sigma(N);
    double dtime = clock() - start_time;

    printf("N = %" PRIu64 "\nSum: %" PRIu64 "\n", N, result);
    printf("Time taken: %.4gms\n", dtime * 1e3 / CLOCKS_PER_SEC);

    return 0;
}
