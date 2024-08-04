

#include <assert.h>    
#include <ctype.h>     
#include <inttypes.h>  
#include <stdbool.h>   
#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    


struct Node
{
    char *word;          
    uint64_t frequency;  
    struct Node *left;   
    struct Node *right;  
};


void endProgramAbruptly(char *errorMessage)
{
    fprintf(stderr, "%s\n", errorMessage);
    exit(EXIT_FAILURE);
}


void freeTreeMemory(struct Node *node)
{
    if (node != NULL)
    {
        freeTreeMemory(node->left);
        freeTreeMemory(node->right);
        free(node->word);  
                           
        free(node);  
    }
}


char *getPointerToWord(char *word)
{
    char *string =
        (char *)malloc((strlen(word) + 1) * sizeof(char));  
    
    if (string != NULL)
    {
        strcpy(string, word);
        return string;
    }
    endProgramAbruptly(
        "\nA problem occurred while reserving memory for the word\n");
    return NULL;
}


void closeFile(FILE *file)
{
    if (fclose(file)) {
        endProgramAbruptly("\nA Problem Occurred while closing a file\n");
     }
}


struct Node *allocateMemoryForNode()
{
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));  
    if (node != NULL)
    {
        return node;
    }
    endProgramAbruptly(
        "\nA problem occurred while reserving memory for the structure\n");
    return NULL;
}


void writeContentOfTreeToFile(struct Node *node, FILE *file)
{
    static uint64_t i = 1;  
    if (node != NULL)       
    {
        writeContentOfTreeToFile(
            node->left,
            file);  
        fprintf(file, "%-5lu \t %-9lu \t %s \n", i++, node->frequency,
                node->word);  
                              
        writeContentOfTreeToFile(
            node->right,
            file);  
    }
}


struct Node *addWordToTree(char *word, struct Node *currentNode)
{
    if (currentNode == NULL)  
    {
        struct Node *currentNode =
            allocateMemoryForNode();  
        currentNode->word = getPointerToWord(word);  
        currentNode->frequency = 1;  
        currentNode->left = NULL;    
        currentNode->right = NULL;   
        return currentNode;          
    }

    int64_t compared = strcmp(word, currentNode->word);  

    if (compared > 0) {
        currentNode->right = addWordToTree(word,
            currentNode->right);  
                                  
    }
    else if (compared < 0) {
        currentNode->left = addWordToTree(word,
            currentNode->left);  
                                 
    }
    else {
        currentNode->frequency++; 
    }

    return currentNode; 
}


struct Node *readWordsInFileToTree(FILE *file, struct Node *root)
{
    
    
    char *inputString =
        (char *)malloc(46 * sizeof(char));  

    char inputChar;                
    bool isPrevCharAlpha = false;  
    uint8_t pos = 0;  

    while ((inputChar = fgetc(file)) != EOF)
    {
        if (pos > 0)
            isPrevCharAlpha = isalpha(inputString[pos - 1]);

        
        if (isalpha(inputChar))
        {
            inputString[pos++] = tolower(inputChar);
            continue;
        }

        
        
        if ((inputChar == '\'' || inputChar == '-') && isPrevCharAlpha)
        {
            inputString[pos++] = inputChar;
            continue;
        }

        
        if (pos == 0)
            continue;

        
        if (!isPrevCharAlpha && inputString[pos - 1] != '\'')
            pos--;
        inputString[pos] = '\0';
        pos = 0;
        isPrevCharAlpha = false;
        root = addWordToTree(inputString, root);
    }

    
    
    if (pos > 0)
    {
        if (!isPrevCharAlpha && inputString[pos - 1] != '\'')
            pos--;
        inputString[pos] = '\0';
        root = addWordToTree(inputString, root);
    }

    free(inputString);
    return root;
}


static void test()
{
    struct Node *root = NULL;  
    FILE *file = NULL;         

    file = fopen("file.txt", "w");  

    fprintf(file,
            "hey_this, is a. test input \n to a_file");  
                                                         

    closeFile(file);                
    file = fopen("file.txt", "r");  

    root = readWordsInFileToTree(file,
                                 root);  

    
    
    assert(strcmp(root->word, "hey") == 0);
    assert(root->frequency == 1);
    assert(strcmp(root->left->word, "a") == 0);
    assert(root->left->frequency == 2);
    assert(strcmp(root->right->word, "this") == 0);
    assert(strcmp(root->left->right->word, "file") == 0);
    assert(strcmp(root->right->left->word, "is") == 0);

    closeFile(file);     
    remove("file.txt");  

    file = fopen("wordcount.txt", "a");  
    fprintf(file, "%-5s \t %9s \t %s \n", "S/N", "FREQUENCY",
            "WORD");  
    writeContentOfTreeToFile(
        root, file);  

    
    char *correctString =
        "S/N   	 FREQUENCY 	 WORD \n"
        "1     	 2         	 a \n"
        "2     	 1         	 file \n"
        "3     	 1         	 hey \n"
        "4     	 1         	 input \n"
        "5     	 1         	 is \n"
        "6     	 1         	 n \n"
        "7     	 1         	 test \n"
        "8     	 1         	 this \n"
        "9     	 1         	 to \n";

    int16_t inputChar;  
    uint64_t i = 0;     

    
    
    while ((inputChar = fgetc(file)) != EOF) {
        assert(inputChar == correctString[i++]);
    }

    closeFile(file);          
    remove("wordcount.txt");  

    freeTreeMemory(root);  
}


int main()
{
    test();  
    return 0;
}
