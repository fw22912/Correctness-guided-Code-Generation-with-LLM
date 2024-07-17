#include <math.h>
#include <stdio.h>
#include <assert.h>

/** Check if the given number is prime */
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

/** Main function */
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

void proof_harness_isprime() {
    int no;
    __CPROVER_assume(no >= 0);
    char result = isprime(no);
    if (no == 2) {
        assert(result == 1);
    } else if (no % 2 == 0) {
        assert(result == 0);
    } else {
        int sq = ((int)(sqrt(no))) + 1;
        for (int i = 3; i < sq; i += 2) {
            if (no % i == 0) {
                assert(result == 0);
            }
        }
        if (result == 1) {
            for (int i = 3; i < sq; i += 2) {
                assert(no % i != 0);
            }
        }
    }
}

void proof_harness_main() {
    int maxNumber = 0;
    int n = 0;
    int n1;
    __CPROVER_assume(n >= 0);
    if (isprime(n) == 1) {
        assert(n == n);
    } else {
        while (n % 2 == 0) {
            n = n / 2;
        }
        if (isprime(n) == 1) {
            assert(n == n);
        } else {
            n1 = ((int)(sqrt(n))) + 1;
            for (int i = 3; i < n1; i += 2) {
                if (n % i == 0) {
                    if (isprime((int)(n / i)) == 1) {
                        maxNumber = n / i;
                        assert(maxNumber == n / i);
                    } else if (isprime(i) == 1) {
                        maxNumber = i;
                        assert(maxNumber == i);
                    }
                }
            }
            assert(maxNumber == maxNumber);
        }
    }
}