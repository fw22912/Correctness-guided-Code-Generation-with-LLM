void proof_harness_getThousand()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '3');
    char *result = getThousand(c);
    if (result != NULL) {
        if (c == '3') {
            assert(strcmp(result, "MMM") == 0);
        }

void proof_harness_getHundred()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getHundred(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "CM") == 0);
        }

void proof_harness_intToRoman()
{
    int num;
    __CPROVER_assume(num >= 1 && num <= 3999);
    char *result = intToRoman(num);
    if (num == 1) {
        assert(strcmp(result, "I") == 0);
    }

void proof_harness_getOne()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getOne(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "IX") == 0);
        }

void proof_harness_getTen()
{
    char c;
    __CPROVER_assume(c >= '0' && c <= '9');
    char *result = getTen(c);
    if (result != NULL) {
        if (c == '9') {
            assert(strcmp(result, "XC") == 0);
        }

