#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#define clear() printf("\033[H\033[J")

void init_board(int row, int col, char board[row][col]);
void print_board(int row, int col, char board[row][col]);

#endif