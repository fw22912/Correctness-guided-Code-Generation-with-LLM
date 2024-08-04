

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
        for (int i = 0; i < N; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum = sum + i;
            }
        }
        printf("%lld\n", sum);  
                                
    }
    return 0;
}
