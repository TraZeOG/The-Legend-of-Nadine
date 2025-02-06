#ifndef _PLAYER_H
#define _PLAYER_H

#include "constants.h"
#include "board.h"



typedef struct {
    int x;
    int y;
} Player;

void move_player(Player* player, Dir dir, board* board);
bool check_collision(Player* player, int x, int y, board* board);
void handle_player_pos(Player* player, board* board);
void interact(Player* player, board* board);

#endif