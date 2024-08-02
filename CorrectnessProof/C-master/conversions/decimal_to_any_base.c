

#include <stdio.h>   
#include <string.h>  
#include <stdint.h>  
#include <stdbool.h> 
#include <assert.h>  
#include <stdlib.h>  


bool isbad_alphabet(const char* alphabet) {
	uint64_t len = strlen(alphabet);
	
		
	if (len < 2) {
		return true;
	}
	
	for (int i = 0; i < len ; i++) {
		 
		if (strchr(alphabet + i + 1, alphabet[i]))
			return true;
	}
	return false;
}


uint64_t converted_len(uint64_t nb, short base) {
	
	if (nb > base - 1) {
		return (converted_len(nb/base, base) + 1);
	}
	return 1;
}


void convertion(uint64_t nb, const char* alphabet, short base, char* converted) {
	
	*(converted) = *(alphabet + nb%base);
	if (nb > base - 1) {
		convertion(nb/base, alphabet, base, --converted);
	}
}


char* decimal_to_anybase(uint64_t nb, const char* alphabet) {
	char* converted;

	
	if (isbad_alphabet(alphabet)) {
		return NULL;
	}
	
	uint64_t base = strlen(alphabet);
	uint64_t final_len = converted_len(nb, base);
	converted = malloc(sizeof(char) * (final_len + 1));
	converted[final_len] = 0;
	convertion(nb, alphabet, base, converted + final_len - 1);
	return converted;
}



static void test()
{
	char* ret = NULL;
	char* reference = NULL;

	
	reference = "0";
	ret = decimal_to_anybase(0, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	
	reference = "18446744073709551615";
	ret = decimal_to_anybase(18446744073709551615, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	
	reference = "18446744073709551615";
	ret = decimal_to_anybase(-1, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}

	
	reference = "101010";
	ret = decimal_to_anybase(42, "01");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	
	reference = "52";
	ret = decimal_to_anybase(42, "01234567");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	
	reference = "2A";
	ret = decimal_to_anybase(42, "0123456789ABCDEF");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	printf("[+] All tests have successfully passed!\n");
}


int main()
{
	test(); 
	return 0;
}
