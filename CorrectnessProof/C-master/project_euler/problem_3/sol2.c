
#include <stdio.h>


int main()
{
    int n = 0;
    scanf("%d", &n);
    int prime = 1;
    int i = 2;
    while (i * i <= n)
    {
        while (n % i == 0)
        {
            prime = i;
            n /= i;
        }
        i += 1;
    }
    if (n > 1)
        prime = n;
    printf("%d\n", prime);
    return 0;
}