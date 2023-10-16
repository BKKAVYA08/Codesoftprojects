#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> initializeBoard() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    return board;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = initializeBoard();
    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameWon && !draw) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) to make your move: ";
        int row, col;
        cin >> row >> col;

        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);
            draw = checkDraw(board);
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    displayBoard(board);

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 1;
}
