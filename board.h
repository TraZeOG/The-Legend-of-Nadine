#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <string.h>

typedef struct {
    Type type;
    int health;
} Bloc;

typedef struct {
    int row;
    int col;
    Bloc** board;
} board;

board* init_board(int row, int col);
void load_chunk(char* name, board* board);
void default_chunk(board* board);

#endif