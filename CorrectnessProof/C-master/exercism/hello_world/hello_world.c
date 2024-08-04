#include "hello_world.h"
#include <stdlib.h>
#include <string.h>

const char *hello(void)
{
    char *ans = strdup("Hello, World!");
    
    return ans;
}
