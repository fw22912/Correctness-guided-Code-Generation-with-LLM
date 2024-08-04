
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif


long long collatz(long long start_num)
{
    long long length = 1;

    while (start_num != 1) 
    {
        if (start_num & 0x01) 
            start_num = 3 * start_num + 1;
        else
            start_num >>= 1; 
        length++;
    }

    return length;
}


int main(int argc, char **argv)
{
    long long max_len = 0, max_len_num = 0;
    long long MAX_NUM = 1000000;

    if (argc ==
        2) 
    {
        MAX_NUM = atoll(argv[1]);
        printf("Maximum number: %lld\n", MAX_NUM);
    }

    long long i;
#ifdef _OPENMP
#pragma omp parallel for shared(max_len, max_len_num) schedule(guided)
#endif
    for (i = 1; i < MAX_NUM; i++)
    {
        long long L = collatz(i);
        if (L > max_len)
        {
            max_len = L;     
            max_len_num = i; 
        }

#if defined(_OPENMP) && defined(DEBUG)
        printf("Thread: %2d\t %3lld: \t%5lld\n", omp_get_thread_num(), i, L);
#elif defined(DEBUG)
        printf("%3lld: \t%5lld\n", i, L);
#endif
    }

    printf("Start: %3lld: \tLength: %5lld\n", max_len_num, max_len);

    return 0;
}
