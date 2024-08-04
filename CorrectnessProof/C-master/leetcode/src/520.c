bool detectCapitalUse(char *word)
{
    int len = strlen(word);
    if (len == 1)
        return 1;
    int countUpper = 0, i;
    for (i = 0; i < len; i++)
    {
        if (isupper(word[i]))
            countUpper++;
    }
    
    if (countUpper == 0)
        return 1;
    
    if (countUpper == 1 && isupper(word[0]))
        return 1;
    
    else
        return countUpper == len;
}


bool isAllUpper(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        if (islower(word[i]))
            return 0;
    }
    return 1;
}
bool detectCapitalUse(char *word)
{
    int len = strlen(word);
    for (int i = 1; i < len; i++)
    {
        if (isupper(word[i]) && !isAllUpper(word))
            return 0;
    }
    return 1;
}
