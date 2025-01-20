#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#define clear() printf("\033[H\033[J")

extern char board[25][130] ;
extern int ROW;
extern int COL;

void init_board(int row, int col, char board[row][col]);
void print_board(int row, int col, char board[row][col]);

#endif