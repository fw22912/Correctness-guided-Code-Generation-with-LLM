

#include <stdio.h> 
#include <stdlib.h> 
#include "malloc_dbg.h" 



int main(int argc, char* argv[])
{
	int* iptr = malloc(10 * sizeof(int));
	char* cptr = calloc(256, sizeof(char));

	free(iptr);
	

	return 0;
}
