
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct sudoku
{
    uint8_t *a; 
    uint8_t N;  
    uint8_t N2; 
};


bool OKrow(const struct sudoku *a, int x, int y, int v)
{
    int offset = x * a->N;
    for (int j = 0; j < a->N; j++)
        if (a->a[offset + j] == v)
            
            return false;
    return true;
}


bool OKcol(const struct sudoku *a, int x, int y, int v)
{
    for (int i = 0; i < a->N; i++)
        if (a->a[i * a->N + y] == v)
            
            return false;
    return true;
}


bool OKbox(const struct sudoku *a, int x, int y, int v)
{
    
    int bi = x - x % a->N2, bj = y - y % a->N2;
    

    for (int i = bi; i < (bi + a->N2); i++)
        for (int j = bj; j < (bj + a->N2); j++)
            if (a->a[i * a->N + j] == v)
                
                return false;
    return true;
}


bool OK(const struct sudoku *a, int x, int y, int v)
{
    bool result = OKrow(a, x, y, v);
    if (result)
        result = OKcol(a, x, y, v);
    if (result)
        result = OKbox(a, x, y, v);

    return result;
}


void print(const struct sudoku *a)
{
    int i, j;
    for (i = 0; i < a->N; i++)
        for (j = 0; j < a->N; j++)
            printf("%" SCNu8 "%c", a->a[i * a->N + j],
                   (j == a->N - 1 ? '\n' : ' '));
}


bool get_next_unknown(const struct sudoku *a, int *x, int *y)
{
    for (int i = 0; i < a->N; i++)
    {
        for (int j = 0; j < a->N; j++)
        {
            if (a->a[i * a->N + j] == 0)
            {
                *x = i;
                *y = j;
                return true;
            }
        }
    }

    
    return false;
}


bool solve(struct sudoku *a)
{
    static uint32_t counter = 0;
    int i, j;
    static char prefix[100] = "";  

    if (!get_next_unknown(a, &i, &j))
    {
        
        return true;
    }

    
    for (uint8_t v = 1; v <= a->N; v++)
    { 
        printf("%sTry (%d,%d) = %" SCNu8 "... ", prefix, i, j, v);
        counter++;
        if (OK(a, i, j, v))
        {
            
            printf("passed (counter=%" SCNu32 ")\n", counter);
            a->a[i * a->N + j] = v;
            strcat(prefix, "  ");
            if (solve(a))
            {
                
                return true;
            }

            printf("%sBacktrack (%d,%d) <- %" SCNu8 " (counter=%" SCNu32 ")\n",
                   prefix, i, j, a->a[i * a->N + j], counter);

            prefix[strlen(prefix) - 2] = '\0';  
            a->a[i * a->N + j] = 0;
        }
        else
        {
            printf("\r");
        }
    }

    return false;
}



void test()
{
    printf("Test begin...\n");

    uint8_t test_array[] = {3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0,
                            0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0,
                            8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0,
                            6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0,
                            0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    struct sudoku a = {.N = 9, .N2 = 3, .a = test_array};
    assert(solve(&a));  

    uint8_t expected[] = {3, 1, 6, 5, 7, 8, 4, 9, 2, 5, 2, 9, 1, 3, 4, 7, 6,
                          8, 4, 8, 7, 6, 2, 9, 5, 3, 1, 2, 6, 3, 4, 1, 5, 9,
                          8, 7, 9, 7, 4, 8, 6, 3, 1, 2, 5, 8, 5, 1, 7, 9, 2,
                          6, 4, 3, 1, 3, 8, 9, 4, 7, 2, 5, 6, 6, 9, 2, 3, 5,
                          1, 8, 7, 4, 7, 4, 5, 2, 8, 6, 3, 1, 9};
    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < a.N; j++)
            assert(a.a[i * a.N + j] == expected[i * a.N + j]);

    printf("Test passed\n");
}


int main()
{
    test();

    struct sudoku a;  
    scanf("%" SCNu8, &(a.N));
    a.a = (uint8_t *)malloc(a.N * a.N * sizeof(uint8_t));
    a.N2 = (uint8_t)sqrt(a.N);

    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < a.N; j++) scanf("%" SCNu8, &(a.a[i * a.N + j]));

    printf("Entered a %udx%ud matrix with block size: %" SCNu8 "\n", a.N, a.N,
           a.N2);
    
    printf("\n\n");
    if (solve(&a))
        printf("Valid solution found!\n");
    else
        printf("Invalid\n");
    print(&a);

    free(a.a);
    return 0;
}
