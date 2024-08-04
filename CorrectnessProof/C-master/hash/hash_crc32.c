
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>


uint32_t crc32(const char* s)
{
    uint32_t crc = 0xffffffff;
    size_t i = 0;
    while (s[i] != '\0')
    {
        uint8_t byte = s[i];
        crc = crc ^ byte;
        for (uint8_t j = 8; j > 0; --j)
        {
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
        }

        i++;
    }
    return crc ^ 0xffffffff;
}


void test_crc32()
{
    assert(crc32("Hello World") == 1243066710);
    assert(crc32("Hello World!") == 472456355);
    assert(crc32("Hello world") == 2346098258);
    assert(crc32("Hello world!") == 461707669);
    printf("Tests passed\n");
}




int main()
{
    test_crc32();
    return 0;
}
