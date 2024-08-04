
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


unsigned long long number_of_paths(int N)
{
    unsigned long long path = 1;
    for (int i = 0; i < N; i++)
    {
        path *= (N << 1) - i;
        path /= i + 1;
    }

    return path;
}


int main(int argc, char **argv)
{
    int N = 20;

    if (argc == 2)
        N = atoi(argv[1]);

    printf("Number of ways to traverse diagonal of %dx%d grid = %llu\n", N, N,
           number_of_paths(N));

    return 0;
}
