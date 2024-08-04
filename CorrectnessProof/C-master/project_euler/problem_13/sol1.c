
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_number(FILE *fp, char *buffer, uint8_t *out_int)
{
    long l = fscanf(fp, "%s\n", buffer);
    if (!l)
    {
        perror("Error reading line.");
        return -1;
    }
    

    long L = strlen(buffer);

    for (int i = 0; i < L; i++)
    {
        if (buffer[i] < 0x30 || buffer[i] > 0x39)
        {
            perror("found inavlid character in the number!");
            return -1;
        }
        else
        {
            out_int[L - i - 1] = buffer[i] - 0x30;
        }
    }

    return 0;
}


int add_numbers(uint8_t *a, uint8_t *b, uint8_t N)
{
    int carry = 0;
    uint8_t *c = b; 

    for (int i = 0; i < N; i++)
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

    for (int i = N; i < N + 10; i++)
    {
        if (carry == 0)
        {
            break;
        }
        
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
        
    }
    return 0;
}


int print_number(uint8_t *number, uint8_t N, int8_t num_digits_to_print)
{
    uint8_t start_pos = N - 1;
    uint8_t end_pos;

    
    while (number[start_pos] == 0) start_pos--;

    
    if (num_digits_to_print < 0)
    {
        end_pos = 0;
    }
    else if (num_digits_to_print <= start_pos)
    {
        end_pos = start_pos - num_digits_to_print + 1;
    }
    else
    {
        fprintf(stderr, "invalid number of digits argumet!\n");
        return -1;
    }

    for (int i = start_pos; i >= end_pos; i--) putchar(number[i] + 0x30);

    putchar('\n');

    return 0;
}


int main(void)
{
    
    const int N = 10;
    
    const int N2 = N + 10;

    
    char *txt_buffer =
        (char *)calloc(N + 5, sizeof(char)); 
    uint8_t *number = (uint8_t *)calloc(
        N, sizeof(uint8_t)); 
    uint8_t *sum = (uint8_t *)calloc(
        N2, sizeof(uint8_t)); 

    FILE *fp = fopen("num.txt", "rt"); 
    if (!fp)
    {
        perror("Unable to open file 'num.txt'.");
        free(txt_buffer);
        free(sum);
        free(number);
        return -1;
    }

    int count = 0;
    get_number(fp, txt_buffer, sum); 
    do
    {
        count++;
        if (get_number(fp, txt_buffer, number) != 0)
        {
            break;
        }
        add_numbers(number, sum, N);
    } while (!feof(fp));

    printf("\nSum   : ");
    print_number(sum, N2, -1);

    printf("first 10 digits: \t");
    print_number(sum, N2, 10);

    fclose(fp); 
    free(txt_buffer);
    free(sum);
    free(number);
    return 0;
}
