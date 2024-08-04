

#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 
#include <assert.h> 



char* run_length_encode(char* str) {
    int str_length = strlen(str);
    int encoded_index = 0;

    
    char* encoded = malloc(2 * strlen(str));
    
    
    char int_str[20];

    for(int i = 0; i < str_length; ++i) {
        int count = 0;
        char current = str[i];

        
        while(current == str[i + count]) count++;

        i += count - 1;

        
        sprintf(int_str, "%d", count);
        int int_str_length = strlen(int_str);
        strncpy(&encoded[encoded_index], int_str, strlen(int_str));

        
        encoded_index += strlen(int_str);
        encoded[encoded_index] = current;
        ++encoded_index;
    }

    
    encoded[encoded_index] = '\0';
    char* compacted_string = malloc(strlen(encoded) + 1);
    strcpy(compacted_string, encoded);
    
    free(encoded);

    return compacted_string;
}


static void test() {
    char* test;
    test = run_length_encode("aaaaaaabbbaaccccdefaadr");
    assert(!strcmp(test, "7a3b2a4c1d1e1f2a1d1r"));
    free(test);
    test = run_length_encode("lidjhvipdurevbeirbgipeahapoeuhwaipefupwieofb");
    assert(!strcmp(test, "1l1i1d1j1h1v1i1p1d1u1r1e1v1b1e1i1r1b1g1i1p1e1a1h1a1p1o1e1u1h1w1a1i1p1e1f1u1p1w1i1e1o1f1bq"));
    free(test);
    test = run_length_encode("htuuuurwuquququuuaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaahghghrw");
    assert(!strcmp(test, "1h1t4u1r1w1u1q1u1q1u1q3u76a1h1g1h1g1h1r1w"));
    free(test);
}


int main() {
    test();  
    printf("All tests have passed!\n");
    return 0;
}
