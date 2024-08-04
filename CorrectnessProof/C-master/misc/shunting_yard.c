

#include <assert.h>     
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <ctype.h>      


int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-': {
            return 1;
        }
        case '*':
        case '/': {
            return 2;
        }
        case '^': {
            return 3;
        }
        default:{
            fprintf(stderr,"Error: Invalid operator\n");
            return -1;
        }
    }
}


int getAssociativity(char operator) {
    switch (operator) {
        case '^': {
            return 0;
        }
        case '+':
        case '-':
        case '*':
        case '/': {
            return 1;
        }
        default: {
            fprintf(stderr,"Error: Invalid operator\n");
            return -1;
        }
    }
}


int shuntingYard(const char *input, char *output) {
    const unsigned int inputLength = strlen(input);
    char* operatorStack = (char*) malloc(sizeof(char) * inputLength);

    
    
    unsigned int stackPointer = 0;

    
    
    char* str = malloc(sizeof(char) * inputLength + 1);
    strcpy(str,input);
    char* token = strtok(str," ");

    
    
    output[0] = '\0';

    while (token != NULL) {
        
        if (isdigit(token[0])) {
            strcat(output,token);
            strcat(output," ");

            token = strtok(NULL," ");
            continue;
        }

        switch (token[0]) {
            
            case '(': {
                operatorStack[stackPointer++] = token[0];
                break;
            }

            
            case ')': {
                
                if(stackPointer < 1) {
                    fprintf(stderr,"Error: Mismatched parentheses\n");
                    free(operatorStack);
                    free(str);
                    return 1;
                }

                while (operatorStack[stackPointer - 1] != '(') {
                    
                    const unsigned int i = (stackPointer--) - 1;
                    strncat(output, &operatorStack[i], 1);
                    strcat(output," ");

                    
                    
                    if(stackPointer == 0) {
                        fprintf(stderr,"Error: Mismatched parentheses\n");
                        free(operatorStack);
                        free(str);
                        return 1;
                    }
                }

                
                
                
                stackPointer--;
                break;
            }

            
            default: {
                
                if(stackPointer < 1) {
                    operatorStack[stackPointer++] = token[0];
                    break;
                }

                
                if((stackPointer - 1 > 0) && operatorStack[stackPointer - 1] != '(') {
                    const int precedence1 = getPrecedence(token[0]);
                    const int precedence2 = getPrecedence(operatorStack[stackPointer - 1]);
                    const int associativity = getAssociativity(token[0]);

                    
                    while ( 
                            ((associativity && precedence1 == precedence2) ||
                             
                             precedence2 > precedence1) &&
                            
                            ((stackPointer - 1 > 0) && operatorStack[stackPointer - 1] != '(')) {

                        strncat(output,&operatorStack[(stackPointer--) - 1],1);
                        strcat(output," ");
                    }
                }

                
                operatorStack[stackPointer++] = token[0];
                break;
            }
        }

        token = strtok(NULL," ");
    }

    free(str);

    
    
    while (stackPointer > 0) {
        
        
        if(operatorStack[stackPointer - 1] == '(') {
            fprintf(stderr,"Error: Mismatched parentheses\n");
            free(operatorStack);
            return 1;
        }

        const unsigned int i = (stackPointer--) - 1;
        strncat(output, &operatorStack[i], 1);
        if (i != 0) {
            strcat(output," ");
        }
    }

    free(operatorStack);
    return 0;
}


static void test() {
    char* in = malloc(sizeof(char) * 50);
    char* out = malloc(sizeof(char) * 50);
    int i;

    strcpy(in,"3 + 4 * ( 2 - 1 )");
    printf("Infix: %s\n",in);
    i = shuntingYard(in, out);
    printf("RPN: %s\n",out);
    printf("Return code: %d\n\n",i);
    assert(strcmp(out,"3 4 2 1 - * +") == 0);
    assert(i == 0);

    strcpy(in,"3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
    printf("Infix: %s\n",in);
    i = shuntingYard(in, out);
    printf("RPN: %s\n",out);
    printf("Return code: %d\n\n",i);
    assert(strcmp(out,"3 4 2 * 1 5 - 2 3 ^ ^ / +") == 0);
    assert(i == 0);

    printf("Testing successfully completed!\n");
    free(in);
    free(out);
}


int main() {
    test(); 
    return 0;
}
