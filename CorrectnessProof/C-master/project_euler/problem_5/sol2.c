
#include <stdio.h>
#include <stdlib.h>


static unsigned int divisors[] = {
    11, 13, 14, 16, 17, 18, 19, 20,
};


static int check_number(unsigned long long n)
{
    for (size_t i = 0; i < 7; ++i)
    {
        if (n % divisors[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}


int main(void)
{
    for (unsigned long long n = 20;; n += 20)
    {
        if (check_number(n))
        {
            printf("Result: %llu\n", n);
            break;
        }
    }
    return 0;
}
