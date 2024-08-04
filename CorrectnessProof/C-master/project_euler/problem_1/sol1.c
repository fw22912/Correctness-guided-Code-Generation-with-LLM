

#include <stdio.h>


int main()
{
    int t;
    printf("Enter number of times you want to try");
    scanf("%d", &t);
    while (t--)  
    {
        unsigned long long N, p = 0, sum = 0;
        printf("Enter the value of N ");

        scanf("%lld", &N);  
        p = (N - 1) / 3;
        sum = ((3 * p * (p + 1)) / 2);

        p = (N - 1) / 5;
        sum = sum + ((5 * p * (p + 1)) / 2);

        p = (N - 1) / 15;
        sum = sum - ((15 * p * (p + 1)) / 2);
        printf("%lld\n", sum);  
                                
    }
    return 0;
}
