





#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26


struct trie {
    struct trie *children[ALPHABET_SIZE];
    bool end_of_word;
};



int trie_new (
    struct trie ** trie
)
{
    *trie = calloc(1, sizeof(struct trie));
    if (NULL == *trie) {
        
        return -1;
    }
    return 0;
}



int trie_insert (
    struct trie * trie,
    char *word,
    unsigned word_len
)
{
    int ret = 0;

    
    
    if (0 == word_len) {
        trie->end_of_word = true;
        return 0;
    }

    
    
    
    const unsigned int index = word[0] - 'a';

    
    
    
    
    if (ALPHABET_SIZE <= index) {
        return -1;
    }

    
    if (NULL == trie->children[index]) {
        ret = trie_new(&trie->children[index]);
        if (-1 == ret) {
            
            return -1;
        }
    }
    
    
    return trie_insert(
         trie->children[index],
         word + 1,
         word_len - 1
    );
}



int trie_search(
    struct trie * trie,
    char *word,
    unsigned word_len,
    struct trie ** result
)
{
    
    if (0 == word_len) {
        *result = trie;
        return 0;
    }

    
    
    const unsigned int index = word[0] - 'a';

    
    
    if (ALPHABET_SIZE <= index) {
        return -1;
    }

    
    if (NULL == trie->children[index]) {
        return -1;
    }

    
    return trie_search(
         trie->children[index],
         word + 1,
         word_len - 1,
         result
    );
}


void trie_print (
    struct trie * trie,
    char prefix[],
    unsigned prefix_len
)
{

    
    if (true == trie->end_of_word) {
        printf("%.*s\n", prefix_len, prefix);
    }

    
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {

        
        if (NULL == trie->children[i]) {
            continue;
        }

        
        
        
        prefix[prefix_len] = i + 'a';

        
        trie_print(trie->children[i], prefix, prefix_len + 1);
    }
}




int main() {
    int ret = 0;
    struct trie * root = NULL;
    struct trie * trie = NULL;
    char word[100] = {0};

    
    ret = trie_new(&root);
    if (-1 == ret) {
        fprintf(stderr, "Could not create trie\n");
        exit(1);
    }

    
    FILE *fp = fopen("dictionary.txt", "r");
    if (NULL == fp) {
        fprintf(stderr, "Error while opening dictionary file");
        exit(1);
    }

    
    while (1 == fscanf(fp, "%100s\n", word)) {
        ret = trie_insert(root, word, strnlen(word, 100));
        if (-1 == ret) {
            fprintf(stderr, "Could not insert word into trie\n");
            exit(1);
        }
    }

    while (1) {
        printf("Enter keyword: ");
        if (1 != scanf("%100s", word)) {
            break;
        }

        printf(
            "\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");

        ret = trie_search(root, word, strnlen(word, 100), &trie);
        if (-1 == ret) {
            printf("No results\n");
            continue;
        }

        trie_print(trie, word, strnlen(word, 100));

        printf("\n==========================================================\n");
    }
}
