#include "board.h"



void init_board(int row, int col, char board[row][col]) {
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

void print_board(int row, int col, char board[row][col]) {
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
