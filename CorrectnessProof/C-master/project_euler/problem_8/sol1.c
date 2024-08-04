
#include <stdio.h>
#include <stdlib.h>


long long int get_product(FILE *fp, long start_pos, int num_digits)
{
    char ch = ' '; 
    unsigned char num = 0;  
    long long int prod = 1; 
    int count =
        0; 

    
    for (int i = 0; i < num_digits; i++, count++)
    {
        
        ch = getc(fp);

        
        if (ch < 0x30 || ch > 0x39)
        {
            if (ch == EOF)
                return 0;
            i--;
            continue;
        }

        num = ch - 0x30; 
        if (num == 0)
        {
            
            
            return 0;
        }

        prod *= num; 
    }

    
    fseek(fp, -count + 1, SEEK_CUR);

    return prod;
}


int main(int argc, char *argv[])
{
    int position = 0;
    int num_digits = 4;
    long long int prod, max_prod = 0;

    
    if (argc == 2)
        num_digits = atoi(argv[1]);

    
    FILE *fp = fopen("digits.txt", "rt");
    if (!fp)
    {
        perror("Unable to open file");
        return -1;
    }

    
    do
    {
        
        prod = get_product(fp, ftell(fp), num_digits);

        if (prod > max_prod)
        {
            max_prod = prod;
            position = ftell(fp) - 1;
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

    return 0;
}
