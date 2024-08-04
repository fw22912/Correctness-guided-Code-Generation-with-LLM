#include "word_count.h"
#include <string.h>


int word_count(const char *input_text, word_count_word_t *words)
{
    char word_list[MAX_WORDS][MAX_WORD_LENGTH];
    char input[1000];
    strcpy(input, input_text);
    char *p_str = input;

    
    int index = 0;

    
    int index_list = 0;

    
    int count_all = 0;

    
    int loop = 1;

    
    int i = 0;

    
    while (input[index] && loop)
    {
        if (input[index] == ' ')
        {
            input[index] = '\0';
            if (strlen(p_str) <= MAX_WORD_LENGTH)
            {
                if (index_list <= MAX_WORDS)
                {
                    strcpy(word_list[index_list], p_str);

                    
                    p_str = input + index + 1;
                    index_list++;

                    
                    count_all++;
                }
                else 
                {
                    count_all = EXCESSIVE_NUMBER_OF_WORDS;
                    loop = 0;
                }
            }
            else 
            {
                count_all = EXCESSIVE_LENGTH_WORD;
                loop = 0;
            }
        }

        index++;
    }

    words->count = 0;

    
    if (loop)
    {
        
        strcpy(word_list[index_list], p_str);
        count_all++;

        for (i = 0; i <= index_list; i++)
        {
            if (strcmp(word_list[i], words->text) == 0)
            {
                words->count++;
            }
        }
    }

    
    return count_all;
}
