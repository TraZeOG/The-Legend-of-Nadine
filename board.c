#include "board.h"



/**
 * @brief Initializes a board with the given number of rows and columns.
 * @param row The number of rows for the board.
 * @param col The number of columns for the board.
 * @return A pointer to the initialized board structure.
 */
board* init_board(int row, int col) {
    clear();
    board* b = malloc(sizeof(board));
    b->board = malloc(sizeof(Bloc) * row);
    for (int i = 0; i < row; i++) {
        b->board[i] = malloc(sizeof(Bloc) * col);
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == col-1) {
                if ((i == 0 || i == row-1) && (j == col/2 || j == col/2 - 1) || (j == 0 || j == col-1) && (i == row/2 || i == row/2 - 1)) {
                    b->board[i][j].type = GATE;
                    b->board[i][j].sprite = SPRITE_GATE;
                }
                else {
                    b->board[i][j].type = WALL;
                    b->board[i][j].sprite = SPRITE_WALL;
                }
            }
            else {
                b->board[i][j].type = VOID;
                b->board[i][j].sprite = SPRITE_VOID;
            }
        }
    }
    b->row = row;
    b->col = col;
    return b;
}
