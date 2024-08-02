
#include <assert.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


long octalToDecimal(long octalValue){
    long decimalValue = 0;
    int i = 0;
    while (octalValue) {
        
        decimalValue += (long)(octalValue % 10) * pow(8, i++);
        
        octalValue /= 10;
    }
    return decimalValue;
}


char *octalToHexadecimal(long octalValue){
    char *hexadecimalValue = malloc(256 * sizeof(char));
    sprintf(hexadecimalValue, "%lX", octalToDecimal(octalValue));
    return hexadecimalValue;
}


static void test() {
    
    assert(strcmp(octalToHexadecimal(213), "8B") == 0);

    
    assert(strcmp(octalToHexadecimal(174), "7C") == 0);
}


int main()
{
    
    test();

    
    int octalValue;
    printf("Enter an octal number: ");
    scanf("%d", &octalValue);

    
    char *hexadecimalValue = octalToHexadecimal(octalValue);
    printf("Equivalent hexadecimal number is: %s", hexadecimalValue);

    
    free(hexadecimalValue);

    
    return 0;
}
