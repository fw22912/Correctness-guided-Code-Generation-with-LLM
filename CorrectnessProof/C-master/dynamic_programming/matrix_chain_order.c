

#include <assert.h>  
#include <limits.h>  
#include <stdio.h>   
#include <stdlib.h>  


int matrixChainOrder(int l, const int *p, int *s)
{
    
    
    int **mat = malloc(l * sizeof(int *));
    for (int i = 0; i < l; ++i)
    {
        mat[i] = malloc(l * sizeof(int));
    }

    for (int i = 0; i < l; ++i)
    {
        mat[i][i] = 0;
    }
    
    
    for (int cl = 1; cl < l; ++cl)
    {
        for (int i = 0; i < l - cl; ++i)
        {
            int j = i + cl;
            mat[i][j] = INT_MAX;
            for (int div = i; div < j; ++div)
            {
                int q = mat[i][div] + mat[div + 1][j] + p[i] * p[div] * p[j];
                if (q < mat[i][j])
                {
                    mat[i][j] = q;
                    s[i * l + j] = div;
                }
            }
        }
    }
    int result = mat[0][l - 1];

    
    for (int i = 0; i < l; ++i)
    {
        free(mat[i]);
    }
    free(mat);

    return result;
}


void printSolution(int l, int *s, int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }
    putchar('(');
    printSolution(l, s, i, s[i * l + j]);
    printSolution(l, s, s[i * l + j] + 1, j);
    putchar(')');
}


static void test()
{
    int sizes[] = {35, 15, 5, 10, 20, 25};
    int len = 6;
    int *sol = malloc(len * len * sizeof(int));
    int r = matrixChainOrder(len, sizes, sol);
    assert(r == 18625);
    printf("Result : %d\n", r);
    printf("Optimal ordering : ");
    printSolution(len, sol, 0, 5);
    free(sol);

    printf("\n");
}


int main()
{
    test();  
    return 0;
}
