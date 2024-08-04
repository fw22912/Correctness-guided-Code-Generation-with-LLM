long numberOfWaysForChar(char * s, char c){
    long firstBuildingAppearNumber = 0;
    long secondBuildingAppearNumber = 0;
    long result = 0;
    
    int sLength = strlen(s);
    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            result += secondBuildingAppearNumber;

            firstBuildingAppearNumber += 1;
            continue;
        }

        secondBuildingAppearNumber += firstBuildingAppearNumber;
    }
    
    return result;
        
}







long long numberOfWays(char * s){
    return numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
}
