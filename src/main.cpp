#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool isValidMove(int row, int col);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
bool checkWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);

int main(){
    runGame();

    return 0;
}

void runGame(){
    string gameBoard[ROWS][COLS];

    initializeGameBoard(gameBoard);

    printCurrentBoard(gameBoard);

    bool playing = true;
    bool xTurn = true; //x starts
    while(playing){
        //get move
        getUserInput(xTurn, gameBoard);

        //board is updated, need to reprint
        printCurrentBoard(gameBoard);

        //check if there is a winner
        if(checkWinner(gameBoard)){
            if(xTurn){
                cout << "X won!";
            }
            else{
                cout << "O won!";
            }
            cout << " Thanks for playing!" << endl;
            playing = false;
            continue;
        }

        //check if baord is full
        if(isBoardFull(gameBoard)){
            cout << "It's a draw! Thanks for playing!" << endl;
            playing = false;
            continue;
        }
        //switch players
        xTurn = !xTurn;
    }
    
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]){
    bool goodMove = false;
    int row, col;
    while(!goodMove){
        if(xTurn){
            cout << "X's turn. ";
        }
        else{
            cout << "O's turn. ";
        }

        cout << "Please enter your move in the format ROW COL i.e. 0 1" << endl;

        cin >> row;
        cin.get();
        cin >> col;

        if(!isValidMove(row, col)){
            cout << "Please enter a valid move." << endl;
            cout << "Row input must be either 0, 1, or 2." << endl;
            cout << "Col input must be either 0, 1, or 2." << endl;
            continue;
        }
        else{
            if(cellAlreadyOccupied(row, col, gameBoard)){
                cout << "That cell is already occupied. Please make another move." << endl;
                continue;
            }
            else{
                goodMove = true;
            }
        }
    }

    //move is valid, update board
    gameBoard[row][col] = (xTurn ? "X" : "O");
}

bool isBoardFull(string gameBoard[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(gameBoard[i][j].compare(" ") == 0){
                return false;
            }
        }
    }

    return true;
}

bool checkWinner(string gameBoard[ROWS][COLS]){
    //check rows
    for(int i = 0; i < ROWS; i++){
        if(gameBoard[i][0].compare(" ") != 0){
            if(gameBoard[i][0].compare(gameBoard[i][1]) == 0
                && gameBoard[i][1].compare(gameBoard[i][2]) == 0){
                    return true;
            }
        }
    }
    //check cols
    for(int j = 0; j < COLS; j++){
        if(gameBoard[0][j].compare(" ") != 0){
            if(gameBoard[0][j].compare(gameBoard[1][j]) == 0
                && gameBoard[1][j].compare(gameBoard[2][j]) == 0){
                    return true;
            }
        }
    }
    //check diagonal starting at row 0
    if(gameBoard[0][0].compare(" ") != 0){
        if(gameBoard[0][0].compare(gameBoard[1][1]) == 0
            && gameBoard[1][1].compare(gameBoard[2][2]) == 0){
                return true;
        }
    }
    //check diagonal starting at row 2
    if(gameBoard[2][0].compare(" ") != 0){
        if(gameBoard[2][0].compare(gameBoard[1][1]) == 0
            && gameBoard[1][1].compare(gameBoard[0][2]) == 0){
                return true;
        }
    }

    return false;
}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]){
    return gameBoard[row][col].compare(" ") != 0;
}

bool isValidMove(int row, int col){
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

void initializeGameBoard(string gameBoard[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            gameBoard[i][j] = " ";
        }
    }
}

void printCurrentBoard(string gameBoard[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << gameBoard[i][j];
            if(j < COLS - 1)
                cout << " | ";
        }
        cout << endl;
        if(i < ROWS - 1){
            cout << "- - - - -";
            cout << endl;
        }
    }
}