
#include <math.h>
#include <stdio.h>


char isprime(int no)
{
    int sq;

    if (no == 2)
    {
        return 1;
    }
    else if (no % 2 == 0)
    {
        return 0;
    }
    sq = ((int)(sqrt(no))) + 1;
    for (int i = 3; i < sq; i += 2)
    {
        if (no % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    int maxNumber = 0;
    int n = 0;
    int n1;
    scanf("%d", &n);
    if (isprime(n) == 1)
        printf("%d", n);
    else
    {
        while (n % 2 == 0)
        {
            n = n / 2;
        }
        if (isprime(n) == 1)
        {
            printf("%d\n", n);
        }
        else
        {
            n1 = ((int)(sqrt(n))) + 1;
            for (int i = 3; i < n1; i += 2)
            {
                if (n % i == 0)
                {
                    if (isprime((int)(n / i)) == 1)
                    {
                        maxNumber = n / i;
                        break;
                    }
                    else if (isprime(i) == 1)
                    {
                        maxNumber = i;
                    }
                }
            }
            printf("%d\n", maxNumber);
        }
    }
    return 0;
}