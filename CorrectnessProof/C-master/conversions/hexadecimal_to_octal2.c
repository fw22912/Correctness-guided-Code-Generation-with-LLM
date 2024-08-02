

#include <stdio.h>  
#include <string.h> 


const char *hex_to_oct(const char *hex)
{
#define MAX_OCT_STR_LEN 23 
    static char octal[MAX_OCT_STR_LEN];
    memset(octal, '\0', MAX_OCT_STR_LEN); 

    unsigned long long decimal = 0;
    int i = 0;
    int len;

    if (hex == NULL)
    {
        
        return octal;
    }

    
    while (*hex != '\n' && *hex != '\0')
    {
        char ch = *hex;

        if (ch >= '0' && ch <= '9')
        {
            ch -= '0';
        }
        else if (ch >= 'a' && ch <= 'f')
        {
            ch = ch - 'a' + 10;
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            ch = ch - 'A' + 10;
        }
        else
        {
            printf("Invalid hexadecimal input: %c\n", ch);
            break;
        }

        decimal *= 16;
        decimal += ch;
        hex++;
    }

    
    if (decimal == 0)
    {
        octal[0] = '0';
        len = 1;
    }
    else
    {
        i = 0;
        while (decimal > 0)
        {
            octal[i] = '0' + decimal % 8;
            i++;
            decimal /= 8;
        }

        len = i;
    }

    octal[len] = '\0';

    
    for (i = 0; i < len / 2; i++)
    {
        char tmp = octal[i];
        octal[i] = octal[len - i - 1];
        octal[len - i - 1] = tmp;
    }

    return octal;
}


int main()
{
#define MAX_HEX_STR_LEN 17 
    char hex[MAX_HEX_STR_LEN];

    
    printf("Enter any hexadecimal number: ");
    fgets(hex, MAX_HEX_STR_LEN, stdin);

    const char *octal = hex_to_oct(hex);

    printf("Hexadecimal number = %s\n", hex);
    printf("Octal number = %s\n", octal);

    return 0;
}
