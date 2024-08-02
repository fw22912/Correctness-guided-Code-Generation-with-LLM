

#include <assert.h> 
#include <stdio.h>  
#include <string.h> 


int symbol(char symbol) {
    int value = 0;
    switch(symbol) {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
    }
    return value;    
}


int roman_to_decimal(char input[]) {
    int result = 0; 

    for(int i = 0; i < strlen(input); i++) {
        if(strlen(input) > i + 1) {
            if(symbol(input[i]) >= symbol(input[i + 1])) {
                result += symbol(input[i]); 
            } else {
                result += symbol(input[i + 1]) - symbol(input[i]); 
                i++; 
            }
        } else {
            result += symbol(input[i]); 
        }
    }
    return result;
}


static void test() {
    
    char input[] = "MCMIV";
    int expected = 1904;
    
    int output = roman_to_decimal(input);

    printf("TEST 1\n");
    printf("Input: %s\n", input);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    
    char input2[] = "MMMDCCXXIV";
    expected = 3724;
    
    output = roman_to_decimal(input2);

    printf("TEST 2\n");
    printf("Input: %s\n", input2);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    
    char input3[] = "III";
    expected = 3;
    
    output = roman_to_decimal(input3);

    printf("TEST 3\n");
    printf("Input: %s\n", input3);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");
}


int main() {
    test();  
    return 0;
}
