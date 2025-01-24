#include "board.h"



board init_board(int row, int col) {
    board* b = malloc(sizeof(board));
    for (int i = 0; i < row; i++) {
        b->board[i] = malloc(sizeof(wchar_t) * col);
        b->board[i][0] = L' ';
        for (int j = 1; j < col; j++) {
            b->board[i][j] = L' ';
        }
    }
    b->row = row;
    b->col = col;
    return *b;
}

void print_board(board b) {
    //clear();
    setlocale(LC_ALL, "");
    for (int i = 0; i < b.row; i++) {
        for (int j = 0; j < b.col; j++) {
            wprintf(L"%lc", b.board[i][j]);
            fflush(stdout);
        }
        wprintf(L"\n");
    }
}
