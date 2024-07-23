#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getOne(char c)
{
    switch (c)
    {
    case '9':
        return "IX";

    case '8':
        return "VIII";

    case '7':
        return "VII";

    case '6':
        return "VI";

    case '5':
        return "V";

    case '4':
        return "IV";

    case '3':
        return "III";

    case '2':
        return "II";

    case '1':
        return "I";

    case '0':
        return "";

    default:
        return NULL;
    }
}

char *getTen(char c)
{
    switch (c)
    {
    case '9':
        return "XC";

    case '8':
        return "LXXX";

    case '7':
        return "LXX";

    case '6':
        return "LX";

    case '5':
        return "L";

    case '4':
        return "XL";

    case '3':
        return "XXX";

    case '2':
        return "XX";

    case '1':
        return "X";

    case '0':
        return "";

    default:
        return NULL;
    }
}

char *getHundred(char c)
{
    switch (c)
    {
    case '9':
        return "CM";

    case '8':
        return "DCCC";

    case '7':
        return "DCC";

    case '6':
        return "DC";

    case '5':
        return "D";

    case '4':
        return "CD";

    case '3':
        return "CCC";

    case '2':
        return "CC";

    case '1':
        return "C";

    case '0':
        return "";

    default:
        return NULL;
    }
}

char *getThousand(char c)
{
    switch (c)
    {
    case '3':
        return "MMM";

    case '2':
        return "MM";

    case '1':
        return "M";

    default:
        return NULL;
    }
}

char *intToRoman(int num)
{
    int length;
    char number[5];
    char *s = malloc(16 * sizeof(char));

    sprintf(number, "%i", num);

    length = strlen(number);

    switch (length)
    {
    case 4:
        sprintf(s, "%s%s%s%s", getThousand(number[0]), getHundred(number[1]),
                getTen(number[2]), getOne(number[3]));
        break;

    case 3:
        sprintf(s, "%s%s%s", getHundred(number[0]), getTen(number[1]),
                getOne(number[2]));

        break;

    case 2:
        sprintf(s, "%s%s", getTen(number[0]), getOne(number[1]));

        break;

    case 1:
        s = getOne(number[0]);
        break;

    default:
        break;
    }
    return s;
}

void proof_harness_getOne()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getOne(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "IX") == 0);
        } else if (c == '8') {
            assert(strcmp(result, "VIII") == 0);
        } else if (c == '7') {
            assert(strcmp(result, "VII") == 0);
        } else if (c == '6') {
            assert(strcmp(result, "VI") == 0);
        } else if (c == '5') {
            assert(strcmp(result, "V") == 0);
        } else if (c == '4') {
            assert(strcmp(result, "IV") == 0);
        } else if (c == '3') {
            assert(strcmp(result, "III") == 0);
        } else if (c == '2') {
            assert(strcmp(result, "II") == 0);
        } else if (c == '1') {
            assert(strcmp(result, "I") == 0);
        } else if (c == '0') {
            assert(strcmp(result, "") == 0);
        }
    } else {
        assert(c < '0' || c > '9');
    }
}

void proof_harness_getTen()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getTen(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "XC") == 0);
        } else if (c == '8') {
            assert(strcmp(result, "LXXX") == 0);
        } else if (c == '7') {
            assert(strcmp(result, "LXX") == 0);
        } else if (c == '6') {
            assert(strcmp(result, "LX") == 0);
        } else if (c == '5') {
            assert(strcmp(result, "L") == 0);
        } else if (c == '4') {
            assert(strcmp(result, "XL") == 0);
        } else if (c == '3') {
            assert(strcmp(result, "XXX") == 0);
        } else if (c == '2') {
            assert(strcmp(result, "XX") == 0);
        } else if (c == '1') {
            assert(strcmp(result, "X") == 0);
        } else if (c == '0') {
            assert(strcmp(result, "") == 0);
        }
    } else {
        assert(c < '0' || c > '9');
    }
}

void proof_harness_getHundred()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getHundred(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "CM") == 0);
        } else if (c == '8') {
            assert(strcmp(result, "DCCC") == 0);
        } else if (c == '7') {
            assert(strcmp(result, "DCC") == 0);
        } else if (c == '6') {
            assert(strcmp(result, "DC") == 0);
        } else if (c == '5') {
            assert(strcmp(result, "D") == 0);
        } else if (c == '4') {
            assert(strcmp(result, "CD") == 0);
        } else if (c == '3') {
            assert(strcmp(result, "CCC") == 0);
        } else if (c == '2') {
            assert(strcmp(result, "CC") == 0);
        } else if (c == '1') {
            assert(strcmp(result, "C") == 0);
        } else if (c == '0') {
            assert(strcmp(result, "") == 0);
        }
    } else {
        assert(c < '0' || c > '9');
    }
}

void proof_harness_getThousand()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '3');
    char *result = getThousand(c);
    if (result != NULL) {
        if (c == '3') {
            assert(strcmp(result, "MMM") == 0);
        } else if (c == '2') {
            assert(strcmp(result, "MM") == 0);
        } else if (c == '1') {
            assert(strcmp(result, "M") == 0);
        }
    } else {
        assert(c < '0' || c > '3');
    }
}

void proof_harness_intToRoman()
{
    int num;
    __CPROVER_assume(num >= 1 && num <= 3999);
    char *result = intToRoman(num);
    if (num == 1) {
        assert(strcmp(result, "I") == 0);
    } else if (num == 2) {
        assert(strcmp(result, "II") == 0);
    } else if (num == 3) {
        assert(strcmp(result, "III") == 0);
    } else if (num == 4) {
        assert(strcmp(result, "IV") == 0);
    } else if (num == 5) {
        assert(strcmp(result, "V") == 0);
    } else if (num == 6) {
        assert(strcmp(result, "VI") == 0);
    } else if (num == 7) {
        assert(strcmp(result, "VII") == 0);
    } else if (num == 8) {
        assert(strcmp(result, "VIII") == 0);
    } else if (num == 9) {
        assert(strcmp(result, "IX") == 0);
    } else if (num == 10) {
        assert(strcmp(result, "X") == 0);
    } else if (num == 11) {
        assert(strcmp(result, "XI") == 0);
    } else if (num == 12) {
        assert(strcmp(result, "XII") == 0);
    } else if (num == 13) {
        assert(strcmp(result, "XIII") == 0);
    } else if (num == 14) {
        assert(strcmp(result, "XIV") == 0);
    } else if (num == 15) {
        assert(strcmp(result, "XV") == 0);
    } else if (num == 16) {
        assert(strcmp(result, "XVI") == 0);
    } else if (num == 17) {
        assert(strcmp(result, "XVII") == 0);
    } else if (num == 18) {
        assert(strcmp(result, "XVIII") == 0);
    } else if (num == 19) {
        assert(strcmp(result, "XIX") == 0);
    } else if (num == 20) {
        assert(strcmp(result, "XX") == 0);
    } else if (num == 21) {
        assert(strcmp(result, "XXI") == 0);
    } else if (num == 22) {
        assert(strcmp(result, "XXII") == 0);
    } else if (num == 23) {
        assert(strcmp(result, "XXIII") == 0);
    } else if (num == 24) {
        assert(strcmp(result, "XXIV") == 0);
    } else if (num == 25) {
        assert(strcmp(result, "XXV") == 0);
    } else if (num == 26) {
        assert(strcmp(result, "XXVI") == 0);
    } else if (num == 27) {
        assert(strcmp(result, "XXVII") == 0);
    } else if (num == 28) {
        assert(strcmp(result, "XXVIII") == 0);
    } else if (num == 29) {
        assert(strcmp(result, "XXIX") == 0);
    } else if (num == 30) {
        assert(strcmp(result, "XXX") == 0);
    } else if (num == 31) {
        assert(strcmp(result, "XXXI") == 0);
    } else if (num == 32) {
        assert(strcmp(result, "XXXII") == 0);
    } else if (num == 33) {
        assert(strcmp(result, "XXXIII") == 0);
    } else if (num == 34) {
        assert(strcmp(result, "XXXIV") == 0);
    } else if (num == 35) {
        assert(strcmp(result, "XXXV") == 0);
    } else if (num == 36) {
        assert(strcmp(result, "XXXVI") == 0);
    } else if (num == 37) {
        assert(strcmp(result, "XXXVII") == 0);
    } else if (num == 38) {
        assert(strcmp(result, "XXXVIII") == 0);
    } else if (num == 39) {
        assert(strcmp(result, "XXXIX") == 0);
    } else if (num == 40) {
        assert(strcmp(result, "XL") == 0);
    } else if (num == 41) {
        assert(strcmp(result, "XLI") == 0);
    } else if (num == 42) {
        assert(strcmp(result, "XLII") == 0);
    } else if (num == 43) {
        assert(strcmp(result, "XLIII") == 0);
    } else if (num == 44) {
        assert(strcmp(result, "XLIV") == 0);
    } else if (num == 45) {
        assert(strcmp(result, "XLV") == 0);
    } else if (num == 46) {
        assert(strcmp(result, "XLVI") == 0);
    } else if (num == 47) {
        assert(strcmp(result, "XLVII") == 0);
    } else if (num == 48) {
        assert(strcmp(result, "XLVIII") == 0);
    } else if (num == 49) {
        assert(strcmp(result, "XLIX") == 0);
    } else if (num == 50) {
        assert(strcmp(result, "L") == 0);
    } else if (num == 51) {
        assert(strcmp(result, "LI") == 0);
    } else if (num == 52) {
        assert(strcmp(result, "LII") == 0);
    } else if (num == 53) {
        assert(strcmp(result, "LIII") == 0);
    } else if (num == 54) {
        assert(strcmp(result, "LIV") == 0);
    } else if (num == 55) {
        assert(strcmp(result, "LV") == 0);
    } else if (num == 56) {
        assert(strcmp(result, "LVI") == 0);
    } else if (num == 57) {
        assert(strcmp(result, "LVII") == 0);
    } else if (num == 58) {
        assert(strcmp(result, "LVIII") == 0);
    } else if (num == 59) {
        assert(strcmp(result, "LIX") == 0);
    } else if (num == 60) {
        assert(strcmp(result, "LX") == 0);
    } else if (num == 61) {
        assert(strcmp(result, "LXI") == 0);
    } else if (num == 62) {
        assert(strcmp(result, "LXII") == 0);
    } else if (num == 63) {
        assert(strcmp(result, "LXIII") == 0);
    } else if (num == 64) {
        assert(strcmp(result, "LXIV") == 0);
    } else if (num == 65) {
        assert(strcmp(result, "LXV") == 0);
    } else if (num == 66) {
        assert(strcmp(result, "LXVI") == 0);
    } else if (num == 67) {
        assert(strcmp(result, "LXVII") == 0);
    } else if (num == 68) {
        assert(strcmp(result, "LXVIII") == 0);
    } else if (num == 69) {
        assert(strcmp(result, "LXIX") == 0);
    } else if (num == 70) {
        assert(strcmp(result, "LXX") == 0);
    } else if (num == 71) {
        assert(strcmp(result, "LXXI") == 0);
    } else if (num == 72) {
        assert(strcmp(result, "LXXII") == 0);
    } else if (num == 73) {
        assert(strcmp(result, "LXXIII") == 0);
    } else if (num == 74) {
        assert(strcmp(result, "LXXIV") == 0);
    } else if (num == 75) {
        assert(strcmp(result, "LXXV") == 0);
    } else if (num == 76) {
        assert(strcmp(result, "LXXVI") == 0);
    } else if (num == 77) {
        assert(strcmp(result, "LXXVII") == 0);
    } else if (num == 78) {
        assert(strcmp(result, "LXXVIII") == 0);
    } else if (num == 79) {
        assert(strcmp(result, "LXXIX") == 0);
    } else if (num == 80) {
        assert(strcmp(result, "LXXX") == 0);
    } else if (num == 81) {
        assert(strcmp(result, "LXXXI") == 0);
    } else if (num == 82) {
        assert(strcmp(result, "LXXXII") == 0);
    } else if (num == 83) {
        assert(strcmp(result, "LXXXIII") == 0);
    } else if (num == 84) {
        assert(strcmp(result, "LXXXIV") == 0);
    } else if (num == 85) {
        assert(strcmp(result, "LXXXV") == 0);
    } else if (num == 86) {
        assert(strcmp(result, "LXXXVI") == 0);
    } else if (num == 87) {
        assert(strcmp(result, "LXXXVII") == 0);
    } else if (num == 88) {
        assert(strcmp(result, "LXXXVIII") == 0);
    } else if (num == 89) {
        assert(strcmp(result, "LXXXIX") == 0);
    } else if (num == 90) {
        assert(strcmp(result, "XC") == 0);
    } else if (num == 91) {
        assert(strcmp(result, "XCI") == 0);
    } else if (num == 92) {
        assert(strcmp(result, "XCII") == 0);
    } else if (num == 93) {
        assert(strcmp(result, "XCIII") == 0);
    } else if (num == 94) {
        assert(strcmp(result, "XCIV") == 0);
    } else if (num == 95) {
        assert(strcmp(result, "XCV") == 0);
    } else if (num == 96) {
        assert(strcmp(result, "XCVI") == 0);
    } else if (num == 97) {
        assert(strcmp(result, "XCVII") == 0);
    } else if (num == 98) {
        assert(strcmp(result, "XCVIII") == 0);
    } else if (num == 99) {
        assert(strcmp(result, "XCIX") == 0);
    } else if (num == 100) {
        assert(strcmp(result, "C") == 0);
    } else if (num == 101) {
        assert(strcmp(result, "CI") == 0);
    } else if (num == 102) {
        assert(strcmp(result, "CII") == 0);
    } else if (num == 103) {
        assert(strcmp(result, "CIII") == 0);
    } else if (num == 104) {
        assert(strcmp(result, "CIV") == 0);
    } else if (num == 105) {
        assert(strcmp(result, "CV") == 0);
    } else if (num == 106) {
        assert(strcmp(result, "CVI") == 0);
    } else if (num == 107) {
        assert(strcmp(result, "CVII") == 0);
    } else if (num == 108) {
        assert(strcmp(result, "CVIII") == 0);
    } else if (num == 109) {
        assert(strcmp(result, "CIX") == 0);
    } else if (num == 110) {
        assert(strcmp(result, "CX") == 0);
    } else if (num == 111) {
        assert(strcmp(result, "CXI") == 0);
    } else if (num == 112) {
        assert(strcmp(result, "CXII") == 0);
    } else if (num == 113) {
        assert(strcmp(result, "CXIII") == 0);
    } else if (num == 114) {
        assert(strcmp(result, "CXIV") == 0);
    } else if (num == 115) {
        assert(strcmp(result, "CXV") == 0);
    } else if (num == 116) {
        assert(strcmp(result, "CXVI") == 0);
    } else if (num == 117) {
        assert(strcmp(result, "CXVII") == 0);
    } else if (num == 118) {
        assert(strcmp(result, "CXVIII") == 0);
    } else if (num == 119) {
        assert(strcmp(result, "CXIX") == 0);
    } else if (num == 120) {
        assert(strcmp(result, "CXX") == 0);
    } else if (num == 121) {
        assert(strcmp(result, "CXXI") == 0);
    } else if (num == 122) {
        assert(strcmp(result, "CXXII") == 0);
    } else if (num == 123) {
        assert(strcmp(result, "CXXIII") == 0);
    } else if (num == 124) {
        assert(strcmp(result, "CXXIV") == 0);
    } else if (num == 125) {
        assert(strcmp(result, "CXXV") == 0);
    } else if (num == 126) {
        assert(strcmp(result, "CXXVI") == 0);
    } else if (num == 127) {
        assert(strcmp(result, "CXXVII") == 0);
    } else if (num == 128) {
        assert(strcmp(result, "CXXVIII") == 0);
    } else if (num == 129) {
        assert(strcmp(result, "CXXIX") == 0);
    } else if (num == 130) {
        assert(strcmp(result, "CXXX") == 0);
    } else if (num == 131) {
        assert(strcmp(result, "CXXXI") == 0);
    } else if (num == 132) {
        assert(strcmp(result, "CXXXII") == 0);
    } else if (num == 133) {
        assert(strcmp(result, "CXXXIII") == 0);
    } else if (num == 134) {
        assert(strcmp(result, "CXXXIV") == 0);
    } else if (num == 135) {
        assert(strcmp(result, "CXXXV") == 0);
    } else if (num == 136) {
        assert(strcmp(result, "CXXXVI") == 0);
    } else if (num == 137) {
        assert(strcmp(result, "CXXXVII") == 0);
    } else if (num == 138) {
        assert(strcmp(result, "CXXXVIII") == 0);
    } else if (num == 139) {
        assert(strcmp(result, "CXXXIX") == 0);
    } else if (num == 140) {
        assert(strcmp(result, "CXL") == 0);
    } else if (num == 141) {
        assert(strcmp(result, "CXLI") == 0);
    } else if (num == 142) {
        assert(strcmp(result, "CXLII") == 0);
    } else if (num == 143) {
        assert(strcmp(result, "CXLIII") == 0);
    } else if (num == 144) {
        assert(strcmp(result, "CXLIV") == 0);
    } else if (num == 145) {
        assert(strcmp(result, "CXLV") == 0);
    } else if (num == 146) {
        assert(strcmp(result, "CXLVI") == 0);
    } else if (num == 147) {
        assert(strcmp(result, "CXLVII") == 0);
    } else if (num == 148) {
        assert(strcmp(result, "CXLVIII") == 0);
    } else if (num == 149) {
        assert(strcmp(result, "CXLIX") == 0);
    } else if (num == 150) {
        assert(strcmp(result, "CL") == 0);
    } else if (num == 151) {
        assert(strcmp(result, "CLI") == 0);
    } else if (num == 152) {
        assert(strcmp(result, "CLII") == 0);
    } else if (num == 153) {
        assert(strcmp(result, "CLIII") == 0);
    } else if (num == 154) {
        assert(strcmp(result, "CLIV") == 0);
    } else if (num == 155) {
        assert(strcmp(result, "CLV") == 0);
    } else if (num == 156) {
        assert(strcmp(result, "CLVI") == 0);
    } else if (num == 157) {
        assert(strcmp(result, "CLVII") == 0);
    } else if (num == 158) {
        assert(strcmp(result, "CLVIII") == 0);
    } else if (num == 159) {
        assert(strcmp(result, "CLIX") == 0);
    } else if (num == 160) {
        assert(strcmp(result, "CLX") == 0);
    } else if (num == 161) {
        assert(strcmp(result, "CLXI") == 0);
    } else if (num == 162) {
        assert(strcmp(result, "CLXII") == 0);
    } else if (num == 163) {
        assert(strcmp(result, "CLXIII") == 0);
    } else if (num == 164) {
        assert(strcmp(result, "CLXIV") == 0);
    } else if (num == 165) {
        assert(strcmp(result, "CLXV") == 0);
    } else if (num == 166) {
        assert(strcmp(result, "CLXVI") == 0);
    } else if (num == 167) {
        assert(strcmp(result, "CLXVII") == 0);
    } else if (num == 168) {
        assert(strcmp(result, "CLXVIII") == 0);
    } else if (num == 169) {
        assert(strcmp(result, "CLXIX") == 0);
    } else if (num == 170) {
        assert(strcmp(result, "CLXX") == 0);
    } else if (num == 171) {
        assert(strcmp(result, "CLXXI") == 0);
    } else if (num == 172) {
        assert(strcmp(result, "CLXXII") == 0);
    } else if (num == 173) {
        assert(strcmp(result, "CLXXIII") == 0);
    } else if (num == 174) {
        assert(strcmp(result, "CLXXIV") == 0);
    } else if (num == 175) {
        assert(strcmp(result, "CLXXV") == 0);
    } else if (num == 176) {
        assert(strcmp(result, "CLXXVI") == 0);
    } else if (num == 177) {
        assert(strcmp(result, "CLXXVII") == 0);
    } else if (num == 178) {
        assert(strcmp(result, "CLXXVIII") == 0);
    } else if (num == 179) {
        assert(strcmp(result, "CLXXIX") == 0);
    } else if (num == 180) {
        assert(strcmp(result, "CLXXX") == 0);
    } else if (num == 181) {
        assert(strcmp(result, "CLXXXI") == 0);
    } else if (num == 182) {
        assert(strcmp(result, "CLXXXII") == 0);
    } else if (num == 183) {
        assert(strcmp(result, "CLXXXIII") == 0);
    } else if (num == 184) {
        assert(strcmp(result, "CLXXXIV") == 0);
    } else if (num == 185) {
        assert(strcmp(result, "CLXXXV") == 0);
    } else if (num == 186) {
        assert(strcmp(result, "CLXXXVI") == 0);
    } else if (num == 187) {
        assert(strcmp(result, "CLXXXVII") == 0);
    } else if (num == 188) {
        assert(strcmp(result, "CLXXXVIII") == 0);
    } else if (num == 189) {
        assert(strcmp(result, "CLXXXIX") == 0);
    } else if (num == 190) {
        assert(strcmp(result, "CXC") == 0);
    } else if (num == 191) {
        assert(strcmp(result, "CXCI") == 0);
    } else if (num == 192) {
        assert(strcmp(result, "CXCII") == 0);
    } else if (num == 193) {
        assert(strcmp(result, "CXCIII") == 0);
    } else if (num == 194) {
        assert(strcmp(result, "CXCIV") == 0);
    } else if (num == 195) {
        assert(strcmp(result, "CXCV") == 0);
    } else if (num == 196) {
        assert(strcmp(result, "CXCVI") == 0);
    } else if (num == 197) {
        assert(strcmp(result, "CXCVII") == 0);
    } else if (num == 198) {
        assert(strcmp(result, "CXCVIII") == 0);
    } else if (num == 199) {
        assert(strcmp(result, "CXCIX") == 0);
    } else if (num == 200) {
        assert(strcmp(result, "CC") == 0);
    } else if (num == 201) {
        assert(strcmp(result, "CCI") == 0);
    } else if (num == 202) {
        assert(strcmp(result, "CCII") == 0);
    } else if (num == 203) {
        assert(strcmp(result, "CCIII") == 0);
    } else if (num == 204) {
        assert(strcmp(result, "CCIV") == 0);
    } else if (num == 205) {
        assert(strcmp(result, "CCV") == 0);
    } else if (num == 206) {
        assert(strcmp(result, "CCVI") == 0);
    } else if (num == 207) {
        assert(strcmp(result, "CCVII") == 0);
    } else if (num == 208) {