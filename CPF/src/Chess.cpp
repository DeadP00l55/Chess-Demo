#include <iostream>
#include <vector>

using namespace std;

// Function to display the chessboard with pieces
void displayBoard(const vector<vector<char>>& board) {
    cout << "   a b c d e f g h" << endl;
    cout << "  -----------------" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " |";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << "|";
        }
        cout << " " << i + 1 << endl;
        cout << "  -----------------" << endl;
    }
    cout << "   a b c d e f g h" << endl;
}

// Function to initialize the chessboard
vector<vector<char>> initializeBoard() {
    vector<vector<char>> board(8, vector<char>(8, ' '));

    // Placing white pieces
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';
    for (int i = 0; i < 8; i++) {
        board[1][i] = 'P';
    }

    // Placing black pieces
    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';
    for (int i = 0; i < 8; i++) {
        board[6][i] = 'p';
    }

    return board;
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<char>>& board, int srcRow, int srcCol, int destRow, int destCol) {
    char piece = board[srcRow][srcCol];

    // Check if the destination is within the bounds of the board
    if (destRow < 0 || destRow >= 8 || destCol < 0 || destCol >= 8) {
        return false;
    }

    // Check if the destination is occupied by a piece of the same color
    if (isupper(piece) && isupper(board[destRow][destCol])) {
        return false;
    }
    if (islower(piece) && islower(board[destRow][destCol])) {
        return false;
    }

    // TODO: Add specific rules for different pieces (e.g., pawn, knight, etc.)

    return true;
}

// Function to move a piece on the chessboard
void movePiece(vector<vector<char>>& board, int srcRow, int srcCol, int destRow, int destCol) {
    board[destRow][destCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = ' ';
}

int main() {
    vector<vector<char>> board = initializeBoard();

    // Display the initial chessboard with pieces
    displayBoard(board);

    // Example of moving a pawn from e2 to e4
    int srcRow = 1;
    int srcCol = 4;
    int destRow = 3;
    int destCol = 4;

    if (isValidMove(board, srcRow, srcCol, destRow, destCol)) {
        movePiece(board, srcRow, srcCol, destRow, destCol);
    } else {
        cout << "Invalid move!" << endl;
    }

    // Display the updated chessboard with pieces
    displayBoard(board);

    return 0;
}




















