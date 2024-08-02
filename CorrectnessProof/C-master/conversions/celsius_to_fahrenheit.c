

#include <assert.h> 
#include <stdio.h>  


 double celcius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
 }


static void test() {
    
    double input = 0.0;
    double expected = 32.0;

    double output = celcius_to_fahrenheit(input);

    
    printf("TEST 1\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    
    input = 100.0;
    expected = 212.0;

    output = celcius_to_fahrenheit(input);

    printf("TEST 2\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    
    input = 22.5;
    expected = 72.5;

    output = celcius_to_fahrenheit(input);

    printf("TEST 3\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");
}


int main() {
    test();  
    return 0;
}
