

#include <assert.h>  
#include <stdint.h>  
#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  


char* convert(char* in, uint16_t numRows)
{
    uint16_t len = strlen(in);

    if (len < numRows)
    {
        numRows = len;
    }
    char* out = calloc(len + 1, sizeof(char));

    if (numRows < 2)
    {
        memcpy(out, in, len + 1);
        return out;
    }

    uint16_t max = numRows - 1;
    uint16_t rr = 2 * max;
    uint16_t i = 0;
    uint16_t o = 0;
    uint16_t delta = 0;

    
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    
    for (uint16_t l = 1; l < max; l++)
    {
        i = l;
        delta = 2 * l;
        while (i < len)
        {
            out[o++] = in[i];
            delta = rr - delta;
            i += delta;
        }
    }

    
    i = max;
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    return out;
}


static void testZigZag(char* s, int numRows, char* expected)
{
    char* ret = convert(s, numRows);
    int len = strlen(s);
    int cmp = strncmp(ret, expected, len);
    assert(!cmp);

    free(ret);
}


static void test()
{
    char* s01 = "PAYPALISHIRING";

    char* r01 = "PINALSIGYAHRPI";
    testZigZag(s01, 4, r01);

    char* r02 = "PAHNAPLSIIGYIR";
    testZigZag(s01, 3, r02);

    char* s03 = "A";
    testZigZag(s03, 1, s03);
    testZigZag(s03, 3, s03);

    char* s04 =
        "cbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaiznicc"
        "ozwknwyhzgpqlwfkjqipuu"
        "jvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfe"
        "rmrnyuqnwbjjpdjhdeavkn"
        "ykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudnegh"
        "bctcbxdxezrzgbpfhzanff"
        "eccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdch"
        "ghrgytzdnobqcvdeqjystm"
        "epxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwa"
        "eeimidfnnzcphkflpbqsvt"
        "dwludsgaungfzoihbxifoprwcjzsdxngtacw";

    char* r04 =
        "cbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaiznicc"
        "ozwknwyhzgpqlwfkjqipuu"
        "jvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfe"
        "rmrnyuqnwbjjpdjhdeavkn"
        "ykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudnegh"
        "bctcbxdxezrzgbpfhzanff"
        "eccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdch"
        "ghrgytzdnobqcvdeqjystm"
        "epxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwa"
        "eeimidfnnzwccpahtkgfnl"
        "xpdbsqzsjvctwdrwploufdisxgbahuinogzf";

    testZigZag(s04, 472, r04);
}


int main(void)
{
    test();  
    return 0;
}
