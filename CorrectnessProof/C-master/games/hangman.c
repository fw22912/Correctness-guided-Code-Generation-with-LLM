

#include <ctype.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 


struct game_instance{

    char current_word[30]; 
    char hidden[30]; 
    int size; 
    int incorrect; 
    char guesses[25]; 
    int guesses_size; 

};


struct game_instance new_game(void); 
int new_guess(char, const char guesses[], int size); 
int in_word(char, const char word[], unsigned int size); 
void picture(int score); 
void won(const char word[], int score); 


int main() {

    struct game_instance game = new_game(); 
    char guess; 

    
    while ((strchr(game.hidden, '_') != NULL) && game.incorrect <= 12) {
        do {
            printf("\n****************************\n");
            printf("Your word: ");

            for (int i = 0; i < game.size; i++) {
                printf("%c ", game.hidden[i]);
            }

            if (game.guesses_size > 0) {
                printf("\nSo far, you have guessed: ");
                for (int i = 0; i < game.guesses_size; i++) {
                    printf("%c ", game.guesses[i]);
                }
            }

            printf("\nYou have %d guesses left.", (12 - game.incorrect));
            printf("\nPlease enter a letter: ");
            scanf(" %c", &guess);
            guess = tolower(guess);

        } while (new_guess(guess, game.guesses, game.guesses_size) != -1);

        game.guesses[game.guesses_size] = guess; 
        game.guesses_size++; 

        if (in_word(guess, game.current_word, game.size) == 1) {
            printf("That letter is in the word!");
            for (int i = 0; i < game.size; i++) {
                if ((game.current_word[i]) == guess) {
                    game.hidden[i] = guess;
                }
            }
        } else {
            printf("That letter is not in the word.\n");
            (game.incorrect)++;
        }
        picture(game.incorrect);
    }

    won(game.current_word, game.incorrect);
    return 0;
}


int new_guess(char new_guess, const char guesses[], int size) {

    for (int j = 0; j < size; j++) {
        if (guesses[j] == new_guess) {
            printf("\nYou have already guessed that letter.");
            return 1;
        }
    }

    return -1;
}


int in_word(char letter, const char word[], unsigned int size) {

    for (int i = 0; i < size; i++) {
        if ((word[i]) == letter) {
            return 1;
        }
    }

    return -1;
}


struct game_instance new_game() {

    char word[30]; 

    FILE *fptr;
    fptr = fopen("games/words.txt", "r");

    if (fptr == NULL){
        fprintf(stderr, "File not found.\n");
        exit(EXIT_FAILURE);
    }

    
    int line_number = 0;
    while (fgets(word, 30, fptr) != NULL) {
        line_number++;
    }

    rewind(fptr);

    
    int random_num;
    srand(time(NULL));
    random_num = rand() % line_number;

    
    int s = 0;
    while (s <= random_num){
        fgets(word, 30, fptr);
        s++;
    }

    
    if (strchr(word, '\n') != NULL){
        word[strlen(word) - 1] = '\0';
    }

    fclose(fptr);

    
    struct game_instance current_game;
    strcpy(current_game.current_word, word);
    current_game.size = strlen(word);
    for (int i = 0; i < (strlen(word)); i++) {
        current_game.hidden[i] = '_';
    }
    current_game.incorrect = 0;
    current_game.guesses_size = 0;

    return current_game;
}


void won(const char word[], int score) {
    if (score > 12) {
        printf("\nYou lost! The word was: %s.\n", word);
    }
    else {
        printf("\nYou won! You had %d guesses left.\n", (12 - score));
    }
}


void picture(int score) {

    switch(score) {

        case 12:
            printf("\n      _\n"
                   "  __( ' )> \n"
                   " \\_ < _ ) ");
            break;

        case 11:
            printf("\n      _\n"
                   "  __( ' )\n"
                   " \\_ < _ ) ");
            break;

        case 10:
            printf("\n      _\n"
                   "  __(   )\n"
                   " \\_ < _ ) ");
            break;

        case 9:
            printf("\n        \n"
                   "  __(   )\n"
                   " \\_ < _ ) ");
            break;

        case 8:
            printf("\n        \n"
                   "  __(    \n"
                   " \\_ < _ ) ");
            break;

        case 7:
            printf("\n        \n"
                   "  __     \n"
                   " \\_ < _ ) ");
            break;

        case 6:
            printf("\n        \n"
                   "  _      \n"
                   " \\_ < _ ) ");
            break;

        case 5:
            printf("\n        \n"
                   "  _      \n"
                   "   _ < _ ) ");
            break;

        case 4:
            printf("\n        \n"
                   "         \n"
                   "   _ < _ ) ");
            break;

        case 3:
            printf("\n        \n"
                   "         \n"
                   "     < _ ) ");
            break;

        case 2:
            printf("\n        \n"
                   "         \n"
                   "       _ ) ");
            break;

        case 1:
            printf("\n        \n"
                   "         \n"
                   "         ) ");
            break;

        case 0:
            break;

        default:
            printf("\n      _\n"
                   "  __( ' )> QUACK!\n"
                   " \\_ < _ ) ");
            break;
    }
}
