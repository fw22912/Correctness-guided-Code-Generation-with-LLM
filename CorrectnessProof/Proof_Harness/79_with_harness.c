#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int getPointKey(int i, int j, int boardSize, int boardColSize){
    return boardSize * boardColSize * i + j;
}

const int directionsSize = 4;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool exitsWord(int i, int j, char** board, int boardSize, int* boardColSize, int wordIndex, char* word, int* vistedPointSet){
    if (board[i][j] != word[wordIndex]){
        return false;
    }
    
    if (wordIndex == strlen(word) - 1){
        return true;
    }
    
    for (int k = 0; k < directionsSize; k++){
        int nextI = i + directions[k][0];
        int nextJ = j + directions[k][1];
        
        if (nextI < 0 || nextI >= boardSize || nextJ < 0 || nextJ >= boardColSize[i]){
            continue;
        }
        
        int key = getPointKey(nextI, nextJ, boardSize, boardColSize[i]);
        if (vistedPointSet[key] == 1){
            continue;
        }
        
        vistedPointSet[key] = 1;
        if (exitsWord(nextI, nextJ, board, boardSize, boardColSize, wordIndex + 1, word, vistedPointSet)){
            return true;
        }

        vistedPointSet[key] = 0;
    }
    
    return false;
}


// Use backtracking.
// Runtime: Runtime: O(n*m*4^len(word))
bool exist(char** board, int boardSize, int* boardColSize, char* word){
    int* vistedPointSet = (int*) calloc(getPointKey(boardSize, boardColSize[0], boardSize, boardColSize[0]), sizeof(int));

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardColSize[i]; j++){
            int key = getPointKey(i, j, boardSize, boardColSize[i]);
            vistedPointSet[key] = 1;
            if (exitsWord(i, j, board, boardSize, boardColSize, 0, word, vistedPointSet)){
                return true;
            };
            
            vistedPointSet[key] = 0;
        }
    }
    
    return false;
}

void proof_harness_getPointKey() {
    int i;
    int j;
    int boardSize;
    int boardColSize;

    __CPROVER_assume(boardSize >= 0);
    __CPROVER_assume(boardColSize >= 0);

    int expected_key = boardSize * boardColSize * i + j;
    int actual_key = getPointKey(i, j, boardSize, boardColSize);

    assert(expected_key == actual_key);
}

void proof_harness_exitsWord() {
    int i;
    int j;
    int boardSize;
    int boardColSize;
    int wordIndex;
    char *word;
    int *vistedPointSet;
    char **board;

    __CPROVER_assume(boardSize >= 0);
    __CPROVER_assume(boardColSize >= 0);
    __CPROVER_assume(wordIndex >= 0);
    __CPROVER_assume(word != NULL);
    __CPROVER_assume(vistedPointSet != NULL);
    __CPROVER_assume(board != NULL);

    bool expected_result = false;

    if (board[i][j] == word[wordIndex]) {
        if (wordIndex == strlen(word) - 1) {
            expected_result = true;
        } else {
            for (int k = 0; k < directionsSize; k++) {
                int nextI = i + directions[k][0];
                int nextJ = j + directions[k][1];

                if (nextI >= 0 && nextI < boardSize && nextJ >= 0 && nextJ < boardColSize) {
                    int key = getPointKey(nextI, nextJ, boardSize, boardColSize);
                    if (vistedPointSet[key] == 0) {
                        vistedPointSet[key] = 1;
                        if (exitsWord(nextI, nextJ, board, boardSize, boardColSize, wordIndex + 1, word, vistedPointSet)) {
                            expected_result = true;
                            break;
                        }
                        vistedPointSet[key] = 0;
                    }
                }
            }
        }
    }

    bool actual_result = exitsWord(i, j, board, boardSize, boardColSize, wordIndex, word, vistedPointSet);

    assert(expected_result == actual_result);
}

void proof_harness_exist() {
    int boardSize;
    int *boardColSize;
    char *word;
    char **board;

    __CPROVER_assume(boardSize >= 0);
    __CPROVER_assume(boardColSize != NULL);
    __CPROVER_assume(word != NULL);
    __CPROVER_assume(board != NULL);

    bool expected_result = false;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            int key = getPointKey(i, j, boardSize, boardColSize[i]);
            if (board[i][j] == word[0]) {
                int *vistedPointSet = (int*) calloc(getPointKey(boardSize, boardColSize[0], boardSize, boardColSize[0]), sizeof(int));
                vistedPointSet[key] = 1;
                if (exitsWord(i, j, board, boardSize, boardColSize, 0, word, vistedPointSet)) {
                    expected_result = true;
                    free(vistedPointSet);
                    break;
                }
                free(vistedPointSet);
            }
        }
        if (expected_result) {
            break;
        }
    }

    bool actual_result = exist(board, boardSize, boardColSize, word);

    assert(expected_result == actual_result);
}

void combined_proof_harness() {
    proof_harness_getPointKey();
    proof_harness_exitsWord();
    proof_harness_exist();
}