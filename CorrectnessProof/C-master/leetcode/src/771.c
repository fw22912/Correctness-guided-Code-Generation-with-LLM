
#include <string.h>

int numJewelsInStones(char *j, char *s)
{
    
    int cnt[500], lens = strlen(s), lenj = strlen(j), sol = 0;
    memset(cnt, 0, sizeof(cnt));

    
    for (int i = 0; i < lenj; i++) cnt[j[i]]++;

    
    for (int i = 0; i < lens; i++) sol += cnt[s[i]];

    return sol;
}
