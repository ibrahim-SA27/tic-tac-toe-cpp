#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize board
void initBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
    currentPlayer = 'X';
}

// Display board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if(j < 2) cout << " |";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check win
bool checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Player move
void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move! Try again.\n";
        makeMove();
    }
}

// Main game loop
void playGame() {
    initBoard();
    while(true) {
        displayBoard();
        makeMove();

        if(checkWin()) {
            displayBoard();
            cout << "Player " << (currentPlayer == 'X' ? 'O' : 'X') << " Wins!\n";
            break;
        }

        if(checkDraw()) {
            displayBoard();
            cout << "It's a Draw!\n";
            break;
        }
    }
}

int main() {
    char again;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> again;
    } while(again == 'y' || again == 'Y');

    return 0;
}