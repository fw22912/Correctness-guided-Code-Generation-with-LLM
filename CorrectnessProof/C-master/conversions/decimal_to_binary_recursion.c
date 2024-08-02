
#include <assert.h>


int decimal_to_binary(unsigned int number)
{
    return number == 0 ? 0 : number % 2 + 10 * decimal_to_binary(number / 2);
}


void test()
{
    const int sets[][2] = {
        {0, 0}, {1, 1}, {2, 10}, {3, 11}, {4, 100}, {6, 110}, {7, 111},
        
    };

    for (int i = 0, size = sizeof(sets) / sizeof(sets[0]); i < size; ++i)
    {
        assert(decimal_to_binary(sets[i][0]) == sets[i][1]);
    }
}


int main()
{
    test();
    return 0;
}
