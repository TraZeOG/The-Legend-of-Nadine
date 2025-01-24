#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#define clear() wprintf(L"\033[H\033[J")

typedef struct {
    int row;
    int col;
    wchar_t** board;
} board;

board* init_board(int row, int col);
void print_board(board* b);

#endif