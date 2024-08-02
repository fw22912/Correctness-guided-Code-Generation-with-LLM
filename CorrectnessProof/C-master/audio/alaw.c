


#include <assert.h>    
#include <inttypes.h>  
#include <stdio.h>     


#define LEN ((size_t)8)


int16_t pcm[LEN] = {1000, -1000, 1234, 3200, -1314, 0, 32767, -32768};


uint8_t r_coded[LEN] = {250, 122, 230, 156, 97, 213, 170, 42};


int16_t r_decoded[LEN] = {1008, -1008, 1248, 3264, -1312, 8, 32256, -32256};


void encode(uint8_t *out, int16_t *in, size_t len)
{
    uint8_t alaw = 0;
    int16_t pcm = 0;
    int32_t sign = 0;
    int32_t abcd = 0;
    int32_t eee = 0;
    int32_t mask = 0;
    for (size_t i = 0; i < len; i++)
    {
        pcm = *in++;
        
        eee = 7;
        mask = 0x4000; 

        
        sign = (pcm & 0x8000) >> 8;

        
        
        pcm = sign ? (-pcm - 1) : pcm;

        
        
        while ((pcm & mask) == 0 && eee > 0)
        {
            eee--;
            mask >>= 1;
        }

        
        abcd = (pcm >> (eee ? (eee + 3) : 4)) & 0x0f;

        
        eee <<= 4;

        
        alaw = (sign | eee | abcd);

        
        *out++ = alaw ^ 0xD5;
    }
}


void decode(int16_t *out, uint8_t *in, size_t len)
{
    uint8_t alaw = 0;
    int32_t pcm = 0;
    int32_t sign = 0;
    int32_t eee = 0;
    for (size_t i = 0; i < len; i++)
    {
        alaw = *in++;

        
        alaw ^= 0xD5;

        
        sign = alaw & 0x80;

        
        eee = (alaw & 0x70) >> 4;

        
        pcm = (alaw & 0x0f) << 4 | 8;

        
        pcm += eee ? 0x100 : 0x0;

        
        pcm <<= eee > 1 ? (eee - 1) : 0;

        
        *out++ = sign ? -pcm : pcm;
    }
}


static void test(int16_t *pcm, uint8_t *coded, int16_t *decoded, size_t len)
{
    
    encode(coded, pcm, len);

    
    for (size_t i = 0; i < len; i++)
    {
        assert(coded[i] == r_coded[i]);
    }

    
    decode(decoded, coded, len);

    
    for (size_t i = 0; i < len; i++)
    {
        assert(decoded[i] == r_decoded[i]);
    }
}


int main(int argc, char *argv[])
{
    
    uint8_t coded[LEN];

    
    int16_t decoded[LEN];

    test(pcm, coded, decoded, LEN);  

    
    printf("inputs: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%d ", pcm[i]);
    }
    printf("\n");

    
    printf("encode: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%u ", coded[i]);
    }
    printf("\n");

    
    printf("decode: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%d ", decoded[i]);
    }
    printf("\n");

    

    return 0;
}
