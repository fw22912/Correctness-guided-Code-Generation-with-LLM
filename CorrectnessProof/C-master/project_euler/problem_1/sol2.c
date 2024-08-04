
#include <stdio.h>


int main()
{
    int n = 0;
    int sum = 0;
    scanf("%d", &n);

    int terms = (n - 1) / 3;
    sum += ((terms) * (6 + (terms - 1) * 3)) / 2;  
    terms = (n - 1) / 5;
    sum += ((terms) * (10 + (terms - 1) * 5)) / 2;
    terms = (n - 1) / 15;
    sum -= ((terms) * (30 + (terms - 1) * 15)) / 2;

    printf("%d\n", sum);
}