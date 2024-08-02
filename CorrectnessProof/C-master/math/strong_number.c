
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>


bool isStrong(int number)
{
    if (number < 0)
    {
        return false;
    }
    int sum = 0;
    int originalNumber = number;
    while (originalNumber != 0)
    {
        int remainder = originalNumber % 10;
        int factorial = remainder == 0 ? 0 : 1; 

        
        for (int i = 1; i <= remainder; factorial *= i, i++)
        {
            ;
        }
        sum += factorial;
        originalNumber /= 10;
    }
    return number == sum;
}


void test()
{
    assert(isStrong(145));  
    assert(!isStrong(543)); 
}


int main()
{
    test();
    return 0;
}
