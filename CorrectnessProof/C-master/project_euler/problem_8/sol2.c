
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main(int argc, char *argv[])
{
    int position = 0, num_bad_chars = 0;
    int num_digits = 4;
    char ch;
    unsigned char num, num_prev;
    unsigned char *buffer = NULL;
    long long int prod = 1, max_prod = 0;

    
    if (argc == 2)
        num_digits = atoi(argv[1]);

    
    buffer = calloc(num_digits, sizeof(unsigned char));
    if (!buffer)
    {
        perror("Unable to allocate memory for buffer");
        return -1;
    }

    
    FILE *fp = fopen("digits.txt", "rt");
    if (!fp)
    {
        perror("Unable to open file");
        free(buffer); 
        return -1;
    }

    
    do
    {
        
        ch = getc(fp);

        
        if (ch < 0x30 || ch > 0x39)
        {
            num_bad_chars++; 
            continue;
        }
        else if (num_bad_chars > 0)
            num_bad_chars--;

        num = ch - 0x30;      
        num_prev = buffer[0]; 

        
        memmove(buffer, buffer + 1, num_digits - 1);
        

        buffer[num_digits - 1] = num; 

        if (num_prev != 0)
        {
            
            prod /= num_prev; 
            prod *= num;
        }
        else
        {
            prod = 1;
            for (int i = 0; i < num_digits; i++)
            {
                if (buffer[i] == 0)
                {
                    prod = 0;
                    break; 
                }
                prod *= buffer[i];
            }
        }

        
        if (prod > max_prod)
        {
            max_prod = prod;
            position = ftell(fp) - num_bad_chars - num_digits - 1;
        }
    } while (!feof(fp)); 

    printf("Maximum product: %lld\t Location: %d^th position\n\t", max_prod,
           position);
    fseek(fp, position,
          SEEK_SET); 
    
    for (; num_digits > 0; num_digits--)
    {
        char ch = getc(fp); 
        
        if (ch < 0x30 || ch > 0x39)
            continue;
        if (num_digits > 1)
            printf("%c x ", ch);
        else
            printf("%c = %lld\n", ch, max_prod);
    }

    fclose(fp);   
    free(buffer); 

    return 0;
}
