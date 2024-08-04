int** initSet(int size){
    int** result = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        result[i] = (int*)calloc(size, sizeof(int));
    }
    
    return result;    
}


int getTripletId(int i, int j){
    return (i / 3) * 3 + (j / 3);
}


bool sudokuSolver(int startI, int startJ, char** board, int boardSize, int* boardColSize, int** horizontalsSets, int** verticalsSets, int** tripletsSets){
    for (int i = startI; i < boardSize; i++) {
        for (int j = startJ; j < boardColSize[i]; j++) {
            if (board[i][j] != '.'){
                continue;
            }
            
            
            int* horizontalSet = horizontalsSets[i];
            int* verticalSet = verticalsSets[j];
            int* tripletsSet = tripletsSets[getTripletId(i, j)];
            
            for (int z = 1; z < 10; z++) {
                if (horizontalSet[z] || verticalSet[z] || tripletsSet[z]){
                    continue;
                }
                
                
                horizontalSet[z] = 1;
                verticalSet[z] = 1;
                tripletsSet[z] = 1;
                
                if (sudokuSolver(i, j + 1, board, boardSize, boardColSize, horizontalsSets, verticalsSets, tripletsSets)){
                    board[i][j] = z + '0';
                    return true;
                }
                
                horizontalSet[z] = 0;
                verticalSet[z] = 0;
                tripletsSet[z] = 0;
            }
            
            
            return false;
        }

        
        startJ = 0;
    }
    
    
    return true;
}


void solveSudoku(char** board, int boardSize, int* boardColSize){
    
    int** horizontalsSets = initSet(boardSize + 1);
    int** verticalsSets = initSet(boardSize + 1);
    int** tripletsSets = initSet(getTripletId(boardSize + 1, boardSize + 1));

    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.'){
                continue;
            }
            
            int value = board[i][j] - '0';
            horizontalsSets[i][value] = 1;
            verticalsSets[j][value] = 1;
            tripletsSets[getTripletId(i, j)][value] = 1;
        }
    }

    
    sudokuSolver(0, 0, board, boardSize, boardColSize, horizontalsSets, verticalsSets, tripletsSets);

    
    free(horizontalsSets);
    free(verticalsSets);
    free(tripletsSets);
}
