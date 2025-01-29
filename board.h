#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "unitech.h"


typedef enum {
    VOID = 0,
    WALL = 1,
    ENEMY = 2,
    LOOT = 3,
    GATE = 4,
    NB_TYPES = 5,
} Type;


typedef enum {
    SPRITE_VOID,
    SPRITE_PLAYER,
    SPRITE_WALL,
    SPRITE_ENEMY,
    SPRITE_LOOT,
    SPRITE_GATE
} Sprite;

typedef struct {
    Type type;
    Sprite sprite;
} Bloc;

typedef struct {
    int row;
    int col;
    Bloc** board;
} board;

board* init_board(int row, int col);

#endif