
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIGITS 1000 


unsigned int add_numbers(unsigned char *a, unsigned char *b, unsigned char *c,
                         int N)
{
    unsigned char carry = 0;
    unsigned int i;

    for (i = 0; i < N; i++)
    {
        
        c[i] = carry + a[i] + b[i];
        if (c[i] > 9) 
        {
            carry = 1;
            c[i] -= 10;
        }
        else
        {
            carry = 0;
        }
        
    }

    while (carry != 0)
    {
        
        
        c[i] = carry + c[i];
        if (c[i] > 9)
        {
            carry = 1;
            c[i] -= 10;
        }
        else
        {
            carry = 0;
        }
        
        i++;
    }
    return i;
}


int print_number(unsigned char *number, int N)
{
    int start_pos = N - 1;

    
    while (number[start_pos] == 0) start_pos--;

    for (int i = start_pos; i >= 0; i--) putchar(number[i] + 0x30);

    return 0;
}


unsigned int get_digits(unsigned char *number)
{
    unsigned int digits = MAX_DIGITS;
    while (number[digits] == 0) digits--;
    return digits;
}


int main(int argc, char *argv[])
{
    unsigned char
        fn[MAX_DIGITS + 1]; 
    unsigned char fn1[MAX_DIGITS + 1];
    unsigned char sum[MAX_DIGITS + 1];

    memset(fn, 0, MAX_DIGITS);
    memset(fn1, 0, MAX_DIGITS);
    memset(sum, 0, MAX_DIGITS);

    fn[0] = 1;
    fn1[1] = 1;

    unsigned int index = 1, digit_count = 1;

    clock_t start_time = clock();
    do
    {
        digit_count = add_numbers(fn, fn1, sum, digit_count);
        

        
        
        

        if (digit_count == MAX_DIGITS)
        {
            break;
        }
        memcpy(fn, fn1, MAX_DIGITS);
        memcpy(fn1, sum, MAX_DIGITS);
        index++;
    } while (digit_count < MAX_DIGITS);
    clock_t end_time = clock();

    printf("Time taken: %.4g ms\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf("The nth term for %d digits: %u \n", MAX_DIGITS, index--);
    print_number(sum, digit_count);

    return 0;
}
