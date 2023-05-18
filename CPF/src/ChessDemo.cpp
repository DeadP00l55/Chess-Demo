#include "ChessDemo.h"

#include <iostream>
#include <vector>

// Function to print the chessboard
void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to initialize the chessboard
std::vector<std::vector<char>> initializeBoard() {
    std::vector<std::vector<char>> board(8, std::vector<char>(8, ' '));
    for (int i = 0; i < 8; ++i) {
        board[1][i] = 'P'; // White pawns
        board[6][i] = 'p'; // Black pawns
    }
    return board;
}

// Function to move a pawn
void movePawn(std::vector<std::vector<char>>& board, int fromX, int fromY, int toX, int toY) {
    // Check if the destination is empty or has an opponent's piece
    if (board[toX][toY] == ' ' || (islower(board[fromX][fromY]) && isupper(board[toX][toY])) || (isupper(board[fromX][fromY]) && islower(board[toX][toY]))) {
        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = ' ';
        std::cout << "Move successful!" << std::endl;
    }
    else {
        std::cout << "Invalid move! You cannot capture your own piece or move to an occupied position." << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> chessboard = initializeBoard();
    bool isWhiteTurn = true; // Variable to track the turn rotation

    while (true) {
        // Print the current chessboard
        printBoard(chessboard);

        int fromX, fromY, toX, toY;

        // Get user input for the pawn's initial and final positions
        std::cout << (isWhiteTurn ? "White's" : "Black's") << " turn:" << std::endl;

        bool validMove = false;

        while (!validMove) {
            std::cout << "Enter the initial position (row, column) of the pawn: ";
            std::cin >> fromX >> fromY;
            std::cout << "Enter the final position (row, column) of the pawn: ";
            std::cin >> toX >> toY;

            // Validate and execute the pawn movement
            if (fromX < 0 || fromX >= 8 || fromY < 0 || fromY >= 8 || toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
                std::cout << "Invalid move! Position out of range." << std::endl;
                continue;
            }

            if (isWhiteTurn && chessboard[fromX][fromY] == 'P') {
                if (toX - fromX == 1 && fromY == toY) {
                    movePawn(chessboard, fromX, fromY, toX, toY);
                    validMove = true;
                    isWhiteTurn = false; // Switch turns
                }
                else {
                    std::cout << "Invalid move! Pawns can only move one step forward." << std::endl;
                }
            }
            else if (!isWhiteTurn && chessboard[fromX][fromY] == 'p') {
                if (fromX - toX == 1 && fromY == toY) {
                    movePawn(chessboard, fromX, fromY, toX, toY);
                    validMove = true;
                    isWhiteTurn = true; // Switch turns
                }
                else {
                    std::cout << "Invalid move! Pawns can only move one step forward." << std::endl;
                }
            }
            else {
                std::cout << "Invalid move! No pawn found at the specified initial position." << std::endl;
            }
        }
    }

    return 0;
}


