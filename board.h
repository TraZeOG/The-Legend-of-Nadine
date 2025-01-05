#ifndef _BOARD_H
#define _BOARD_H

char board[25][130] ;
int ROW = 25;
int COL = 130;

void init_board(int row, int col, char board[row][col]);
void print_board(int row, int col, char board[row][col]);

#endif