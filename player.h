#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef enum { //names speak for themselves
    NORTH = 'z',
    EAST = 'd',
    SOUTH = 's',
    WEST = 'q'
} Dir;

typedef struct {
    int x;
    int y;
} Coord;
Coord player = {20, 20};

void move_player(Coord* player, Dir dir);
bool check_collision(Coord cos);

#endif