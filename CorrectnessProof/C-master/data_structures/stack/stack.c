

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


void **array;


int max = 10;


int counter = 0;


int offset = -1;

void initStack()
{
    array = malloc(sizeof(void *) * max);
    assert(array); 
}


void grow()
{
    max += 10; 

    int i;  
    void **tmp = malloc(sizeof(void *) * max);

    
    for (i = 0; i < max - 10; i++)
    {
        *(tmp + i) = *(array + i);
    }
    
    free(array);
    array = tmp;
}


void push(void *object)
{
    assert(object); 

    if (counter < max)
    {
        offset++; 

        
        *(array + offset) = object;

        
        counter++;
    }
    else 
    {
        grow();       
        push(object); 
    }
}


void *pop()
{
    void *top = *(array + offset);

    
    assert(top);

    
    assert(!isEmpty());

    
    offset--;

    
    counter--;

    return top;
}


int size() { return counter; }


int isEmpty() { return counter == 0; }


void *top()
{
    
    return array[offset];
}
