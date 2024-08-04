

#include <assert.h>  
#include <math.h>    
#include <stdio.h>   

#define EPSILON 0.0001  
#define NMAX 50         


double sign(double a, double b)
{
    return (a > 0 && b > 0) + (a < 0 && b < 0) - (a > 0 && b < 0) -
           (a < 0 && b > 0);
}


double func(double x)
{
    return x * x * x + 2.0 * x - 10.0;  
}


double bisection(double x_left, double x_right, double tolerance)
{
    int n = 1;      
    double middle;  

    while (n <= NMAX)
    {
        middle = (x_left + x_right) / 2;  
        double error = middle - x_left;

        if (fabs(func(middle)) < EPSILON || error < tolerance)
        {
            return middle;
        }

        if (sign(func(middle), func(x_left)) > 0.0)
        {
            x_left = middle;  
        }
        else
        {
            x_right = middle;  
        }

        n++;  
    }
    return -1;  
}


static void test()
{
    
    assert(fabs(bisection(1.0, 2.0, 0.0001) - 1.847473) <
           EPSILON);  
    assert(fabs(bisection(100.0, 250.0, 0.0001) - 249.999928) <
           EPSILON);  

    printf("All tests have successfully passed!\n");
}


int main()
{
    test();  
    return 0;
}
