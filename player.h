#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdbool.h>
#include <stdlib.h>
#include "constants.h"
#include "board.h"

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    int x;
    int y;
} Player;

void move_player(Player* player, Dir dir, board* board);
bool check_collision(Player* player, int x, int y, board* board);

#endif