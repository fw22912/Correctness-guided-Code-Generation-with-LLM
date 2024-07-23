#include <assert.h>  /// for assert
#include <stdint.h>  /// for unsigned int with fixed size
#include <stdio.h>   /// for IO operations
#include <stdlib.h>  /// for malloc
#include <string.h>  /// for string tools

/**
 * @brief Convert a string to the it's zigzag equivalent on a given number of
 * rows.
 * @param in the string in input.
 * @param numRows the desired number of rows.
 * @returns the converted new (malloced) string.
 */
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

    // first row
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    // middle rows
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

    // last row
    i = max;
    while (i < len)
    {
        out[o++] = in[i];
        i += rr;
    }

    return out;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void testZigZag(char* s, int numRows, char* expected)
{
    char* ret = convert(s, numRows);
    int len = strlen(s);
    int cmp = strncmp(ret, expected, len);
    assert(!cmp);

    free(ret);
}

/**
 * @brief Self-test implementations
 * @returns void
 */
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

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void)
{
    test();  // run self-test implementations
    return 0;
}

void proof_harness_convert() {
    char *in = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(in != NULL);
    uint16_t numRows;
    __CPROVER_assume(numRows > 0);
    __CPROVER_assume(numRows <= 1024);
    convert(in, numRows);
    free(in);
}

void proof_harness_testZigZag() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int numRows;
    __CPROVER_assume(numRows > 0);
    __CPROVER_assume(numRows <= 1024);
    char *expected = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(expected != NULL);
    testZigZag(s, numRows, expected);
    free(s);
    free(expected);
}

void proof_harness_test() {
    test();
}

void proof_harness_main() {
    main();
}

void combined_proof_harness() {
    proof_harness_convert();
    proof_harness_testZigZag();
    proof_harness_test();
    proof_harness_main();
}