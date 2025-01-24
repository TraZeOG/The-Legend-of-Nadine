#include "board.h"



void init_board(int row, int col, wchar_t board[row][col]) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (i==0 || i==row-1) {
                board[i][j] = '=';
            }
            else if (j==0 || j==col-1) {
                board[i][j] = '|';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(int row, int col, wchar_t board[row][col]) {
    clear();
    setlocale(LC_ALL, "");
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            wprintf(L"%lc", board[i][j]);
            wprintf(L"🌳rorar je suis un arbre");
            fflush(stdout);
        }
        wprintf(L"\n");
    }
}
