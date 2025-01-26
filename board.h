#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "unitech.h"

typedef struct {
    int row;
    int col;
    wchar_t** board;
} board;

board* init_board(int row, int col);

#endif