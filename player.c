#include "player.h"



void move_player(Coord* player, Dir input) {
    if (input == NORTH && player->y > 0) player->y--;
    if (input == SOUTH && player->y < 40) player->y++;
    if (input == WEST && player->x > 0) player->x--;
    if (input == EAST && player->x < 40) player->x++;
}
