
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>


uint64_t djb2(const char* s)
{
    uint64_t hash = 5381; 
    size_t i = 0;
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
    return hash;
}


void test_djb2(void)
{
    assert(djb2("Hello World") == 13827776004929097857);
    assert(djb2("Hello World!") == 13594750393630990530);
    assert(djb2("Hello world") == 13827776004967047329);
    assert(djb2("Hello world!") == 13594750394883323106);
    printf("Tests passed\n");
}




int main()
{
    test_djb2();
    return 0;
}
