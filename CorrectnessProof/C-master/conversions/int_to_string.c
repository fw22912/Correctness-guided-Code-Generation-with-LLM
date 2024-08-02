
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *int_to_string(uint16_t value, char *dest, int base)
{
    const char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    int len = 0;
    do
    {
        dest[len++] = hex_table[value % base];
        value /= base;
    } while (value != 0);

    
    for (int i = 0, limit = len / 2; i < limit; ++i)
    {
        char t = dest[i];
        dest[i] = dest[len - 1 - i];
        dest[len - 1 - i] = t;
    }
    dest[len] = '\0';
    return dest;
}


static void test()
{
    const int MAX_SIZE = 100;
    char *str1 = (char *)calloc(sizeof(char), MAX_SIZE);
    char *str2 = (char *)calloc(sizeof(char), MAX_SIZE);

    for (int i = 1; i <= 100; ++i) 
    {
        
        int value = rand() % 100;

        
        
        snprintf(str1, MAX_SIZE, "%o", value);  /
        assert(strcmp(str1, int_to_string(value, str2, 8)) == 0);
        snprintf(str1, MAX_SIZE, "%d", value); 
        assert(strcmp(str1, int_to_string(value, str2, 10)) == 0);
        snprintf(str1, MAX_SIZE, "%x", value); 
        assert(strcmp(str1, int_to_string(value, str2, 16)) == 0);
    }

    free(str1);
    free(str2);
}


int main()
{
    
    srand(time(NULL));
    test();
    return 0;
}
