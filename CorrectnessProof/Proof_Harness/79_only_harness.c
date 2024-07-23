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

void combined_proof_harness() {
    proof_harness_getPointKey();
    proof_harness_exitsWord();
    proof_harness_exist();
}

