

#include <stdio.h>      
#include <assert.h>     
#include <math.h>       
#include <inttypes.h>   


int convert_to_decimal(uint64_t number) {
    int decimal_number = 0, i = 0;

    while (number > 0) {
        decimal_number += (number % 10) * pow(2, i);
        number = number / 10;
        i++;
    }

    return decimal_number;
}


static void tests() {
    assert(convert_to_decimal(111) == 7);
    assert(convert_to_decimal(101) == 5);
    assert(convert_to_decimal(1010) == 10);
    assert(convert_to_decimal(1101) == 13);
    assert(convert_to_decimal(100001) == 33);
    assert(convert_to_decimal(10101001) == 169);
    assert(convert_to_decimal(111010) == 58);
    assert(convert_to_decimal(100000000) == 256);
    assert(convert_to_decimal(10000000000) == 1024);
    assert(convert_to_decimal(101110111) == 375);

    printf("All tests have successfully passed!\n");
}


int main()
{
    tests();  
    return 0;
}
