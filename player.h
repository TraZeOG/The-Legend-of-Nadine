#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdbool.h>
#include <stdlib.h>
#include "unitech.h"
#include "board.h"

typedef enum {
    NORTH = 'z',
    EAST = 'd',
    SOUTH = 's',
    WEST = 'q'
} Dir;

typedef struct {
    int x;
    int y;
} Coord;

void move_player(Coord* player, Dir dir, board board);
bool check_collision(Coord coss);

#endif