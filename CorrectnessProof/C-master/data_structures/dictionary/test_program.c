

#include <stdio.h>


#include "dict.h"

int main(void)
{
    Dictionary *testObj1;
    Dictionary *testObj2;

    int value = 28;

    testObj1 = create_dict();
    testObj2 = create_dict();

    add_item_label(testObj1, "age", &value);
    add_item_label(testObj2, "name", "Christian");

    
    printf("My age is %d\n", *((int *)get_element_label(testObj1, "age")));
    printf("My name is %s\n", get_element_label(testObj2, "name"));

    
    if (!add_item_index(testObj1, 0, &value))
    {
        printf("My age at index %d is %d\n", 0,
               *((int *)get_element_index(testObj1, 0)));
    }

    
    

    
    destroy(testObj1);
    destroy(testObj2);

    return 0;
}