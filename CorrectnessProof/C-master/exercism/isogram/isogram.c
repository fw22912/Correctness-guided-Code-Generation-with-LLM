#include <stdbool.h>
#include <string.h>


bool is_isogram(const char phrase[])
{
    
    unsigned int i = 0;
    unsigned int j = 0;

    
    char current_char = ' ';

    
    bool status = true;

    
    unsigned int len_phrase = strlen(phrase);

    for (i = 0; i < len_phrase; i++)
    {
        current_char = phrase[i];

        
        for (j = i + 1; j < len_phrase; j++)
        {
            if (current_char == phrase[j])
            {
                status = false;

                
                goto end;
            }
        }
    }


end:
    return status;
}