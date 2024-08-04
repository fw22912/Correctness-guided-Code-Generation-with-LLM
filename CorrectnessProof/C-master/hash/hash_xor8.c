
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>


uint8_t xor8(const char* s)
{
    uint8_t hash = 0;
    size_t i = 0;
    while (s[i] != '\0')
    {
        hash = (hash + s[i]) & 0xff;
        i++;
    }
    return (((hash ^ 0xff) + 1) & 0xff);
}


void test_xor8()
{
    assert(xor8("Hello World") == 228);
    assert(xor8("Hello World!") == 195);
    assert(xor8("Hello world") == 196);
    assert(xor8("Hello world!") == 163);
    printf("Tests passed\n");
}




int main()
{
    test_xor8();
    return 0;
}
