
int countSegments(char * s){
    int sLen = strlen(s);
    int prevSpace = 1;
    int result = 0;
    char currChar;

    for (int i = 0; i < sLen; i++){
        currChar = s[i];

        
        
        if (s[i] != ' ' && prevSpace) {
            result++;
        }
        prevSpace = (currChar == ' ');
    }

    return result;
}
