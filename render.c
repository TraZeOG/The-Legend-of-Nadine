#include "render.h"



/**
 * @brief Prints the board to the console.
 * @param b A pointer to the board structure to be printed.
 */
void print_board(board* b) {
    clear();
    setlocale(LC_ALL, "");
    for (int i = 0; i < b->row; i++) {
        for (int j = 0; j < b->col; j++) {
            if (b->board[i][j] == L' ') {
                wprintf(L"  ");
            } else {
                wprintf(L"%lc", b->board[i][j]);
            }
        }
        wprintf(L"\n");
        fflush(stdout);
    }
}