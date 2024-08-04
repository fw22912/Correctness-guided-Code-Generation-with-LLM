
#include <stdio.h>


int main()
{
    int n = 0;
    int sum = 0;
    int num = 0;
    scanf("%d", &n);

    while (1)
    {
        num += 3;
        if (num >= n)
            break;
        sum += num;
        num += 2;
        if (num >= n)
            break;
        sum += num;
        num += 1;
        if (num >= n)
            break;
        sum += num;
        num += 3;
        if (num >= n)
            break;
        sum += num;
        num += 1;
        if (num >= n)
            break;
        sum += num;
        num += 2;
        if (num >= n)
            break;
        sum += num;
        num += 3;
        if (num >= n)
            break;
        sum += num;
    }

    printf("%d\n", sum);
    return 0;
}