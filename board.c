#include "board.h"
#include <stdlib.h>
#include <locale.h>



/**
 * @brief Initializes a board with the given number of rows and columns.
 * @param row The number of rows for the board.
 * @param col The number of columns for the board.
 * @return A pointer to the initialized board structure.
 */
board* init_board(int row, int col) {
    clear();
    board* b = malloc(sizeof(board));
    b->board = malloc(sizeof(wchar_t*) * row);
    for (int i = 0; i < row; i++) {
        b->board[i] = malloc(sizeof(wchar_t) * col);
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == col-1) {
                b->board[i][j] = L'\U0001F9F1';
            } else {
                b->board[i][j] = L' ';
            }
        }
    }
    b->row = row;
    b->col = col;
    return b;
}

/**
 * @brief Prints the board to the console.
 * @param b A pointer to the board structure to be printed.
 */
void print_board(board* b) {
    clear();
    setlocale(LC_ALL, "");
    for (int i = 0; i < b->row; i++) {
        for (int j = 0; j < b->col; j++) {
            wprintf(L"%lc", b->board[i][j]);
        }
        wprintf(L"\n");
        fflush(stdout);
    }
}
