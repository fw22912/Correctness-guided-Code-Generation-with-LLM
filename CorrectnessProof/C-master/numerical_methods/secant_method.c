

#include <assert.h>  
#include <math.h>    
#include <stdio.h>   

#define TOLERANCE 0.0001  
#define NMAX 100          


double func(double x)
{
    return x * x - 3.;  
}


double secant_method(double x0, double x1, double tolerance)
{
    int n = 1;  

    while (n++ < NMAX)
    {
        
        double x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));

        
        x0 = x1;
        x1 = x2;

        
        if (fabs(x1 - x0) < tolerance)
            return x2;
    }

    return -1;  
}


static void test()
{
    
    assert(secant_method(0.2, 0.5, TOLERANCE) - sqrt(3) < TOLERANCE);
    assert(fabs(secant_method(-2, -5, TOLERANCE)) - sqrt(3) < TOLERANCE);
    assert(secant_method(-3, 2, TOLERANCE) - sqrt(3) < TOLERANCE);
    assert(fabs(secant_method(1, -1.5, TOLERANCE)) - sqrt(3) < TOLERANCE);

    printf("All tests have successfully passed!\n");
}


int main()
{
    test();  
    return 0;
}
