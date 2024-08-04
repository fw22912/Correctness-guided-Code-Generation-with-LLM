#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *abbreviate(const char *phrase)
{
    char str[80];
    strcpy(str, phrase);
    char *p_str = str;
    static char acr[80];
    strcpy(acr, "");

    
    int counter = 0;

    
    int index = 0;

    
    int i = 0;

    
    while (p_str && (i < 80))
    {
        if (*p_str == ' ')
        {
            counter++;
        }
        if (i < 80)
        {
            p_str++;
            i++;
        }
    }

    i = 0;
    counter++;
    char **words = (char **)malloc(counter * sizeof(char *));

    
    for (i = 0; i < counter; i++)
    {
        words[i] = (char *)malloc(80 * sizeof(char));
        strcpy(words[i], "");
    }

    
    p_str = str;

    char *p_start = p_str;

    
    while (p_str && (i <= 80))
    {
        if (*p_str == ' ')
        {
            *p_str = '\0';
            strncat(words[index], p_start, 80);
            index++;
            p_start = p_str + 1;
        }

        if (i <= 80)
        {
            p_str++;
            i++;
        }
    }

    
    *p_str = '\0';
    strncat(words[index], p_start, 80);
    index++;

    
    for (i = 0; i < index; i++)
    {
        
        words[i][0] = toupper(words[i][0]);
        words[i][1] = '\0';
        strcat(acr, words[i]);
    }

    for (i = 0; i < counter; i++) free(words[i]);
    free(words);

    return acr;
}
