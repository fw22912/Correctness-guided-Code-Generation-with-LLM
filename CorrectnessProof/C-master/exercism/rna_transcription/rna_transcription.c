#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char s[])
{
    
    int len = strlen(s);

    
    char *ans = malloc(sizeof(char) * len);

    
    int i = 0;

    
    for (i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'G':
            ans[i] = 'C';
            break;
        case 'C':
            ans[i] = 'G';
            break;
        case 'T':
            ans[i] = 'A';
            break;
        case 'A':
            ans[i] = 'U';
            break;
        }
    }

    return ans;
}