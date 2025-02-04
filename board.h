#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "unitech.h"
#include <string.h>


typedef enum {
    VOID = 0,
    PLAYER = 1,
    WALL = 2,
    ENEMY = 3,
    LOOT = 4,
    GATE = 5,
} Type;

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