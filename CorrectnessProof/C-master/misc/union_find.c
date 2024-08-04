
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000 


int find(int *p, int x)
{
    if (x >= MAX_SIZE)
    {
        fprintf(stderr, "Out-of bounds value\n");
        exit(EXIT_FAILURE);
    }

    if (p[x] == x)
    {
        return x;
    }
    else
    {
        p[x] = find(p, p[x]);
        return p[x];
    }
}


void join(int *p, int x, int y) { p[find(p, x)] = find(p, y); }


int main()
{
    int union_set[MAX_SIZE];

    
    for (int i = 0; i < 10; i++)
    {
        union_set[i] = i;
    }
    

    join(union_set, 3, 5);
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");
    
    

    join(union_set, 3, 8);
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");

    
    
    join(union_set, 0, 5);
    if (find(union_set, 0) == find(union_set, 3))
    {
        printf("0 and 3 are groupped together\n");
    }
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");

    return 0;
}
