#include "dict.h"
#include <stdio.h>
#include <stdlib.h>


Dictionary *create_dict(void)
{
    Dictionary *p_dic = malloc(sizeof(Dictionary));
    if (p_dic)
    {
        p_dic->number_of_elements = 0;

        
        for (int i = 0; i < MAXELEMENTS; i++)
        {
            p_dic->elements[i] = NULL;
        }

        return p_dic;
    }
    else
    {
        printf("unable to create a dictionary\n");
        return NULL;
    }
}


int get_hash(char s[])
{
    unsigned int hash_code = 0;

    
    for (int counter = 0; s[counter] != '\0'; counter++)
    {
        
        hash_code =
            s[counter] + (hash_code << 6) + (hash_code << 16) - hash_code;
    }

    
    return hash_code % MAXELEMENTS;
}

int add_item_label(Dictionary *dic, char label[], void *item)
{
    unsigned int index = get_hash(label);

    
    if (index < MAXELEMENTS)
    {
        dic->elements[index] = item;
        return 0;
    }

    
    return -1;
}

int add_item_index(Dictionary *dic, int index, void *item)
{
    
    if (!dic->elements[index])
    {
        dic->elements[index] = item;
        return 0;
    }

    
    return -1;
}

void *get_element_label(Dictionary *dict, char s[])
{
    int index = get_hash(s);
    if (dict->elements[index])
    {
        return dict->elements[index];
    }

    printf("None entry at given label\n");
    return NULL;
}

void *get_element_index(Dictionary *dict, int index)
{
    if (index >= 0 && index < MAXELEMENTS)
    {
        return dict->elements[index];
    }

    printf("index out of bounds!\n");
    return NULL;
}

void destroy(Dictionary *dict) { free(dict); }