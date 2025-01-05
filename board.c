#include "board.h"

void init_board(int row, int col, char board[row][col]) {
    for (int j = 0; j < col; j++) {
        if (j%4 == 0 || j%4 == 1) {
            board[0][j] = '=' ;
        } else {
            board[0][j] = '-' ;
        }
        
    }
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++)
            board[i][j] = ' ' ;
    }
}

void print_board(int row, int col, char board[row][col]) {
    clear();
    for (int i = row-1; i >= 0 ; i--) {
        for (int j = 0; j < col; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}