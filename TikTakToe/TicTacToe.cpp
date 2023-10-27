#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

void printBoard() {
    system("clear");  // Clear the terminal (UNIX/Linux/macOS)
    // system("cls"); // Use this for Windows

    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool isGameOver() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
    }
    return draw;
}

int main() {
    int row, col;
    bool validMove;

    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        validMove = makeMove(row - 1, col - 1);

        if (!validMove) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (isGameOver()) {
            printBoard();
            if (currentPlayer == 'X')
                cout << "Player X wins!\n";
            else
                cout << "Player O wins!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
