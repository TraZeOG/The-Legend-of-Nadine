#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef char Type ;
typedef char chunck ;

typedef enum { //names speak for themselves
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
} Dir;

typedef struct {
    int x;
    int y;
} Coord;

void save();
void load();
void move_player(Coord cos,Dir dir);
bool check_collision(Coord cos);

#endif