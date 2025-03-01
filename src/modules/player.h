#ifndef _PLAYER_H
#define _PLAYER_H

#include "constants.h"
#include "board.h"



typedef struct {
    int x;
    int y;
    int health;
    int alt_x;
    int alt_y;
    int chunk_x;
    int chunk_y;
    int status;
} Player;

void move_player(Player* player, Dir dir, Board* board, Map* map);
void put_player_on_board(Board* board, Player* player);
bool check_collision(Player* player, int x, int y, Board* board);
void handle_player_pos(Player* player, Board* board, Map* map);
void handle_map(Player* player, Map* map);
void interact(Player* player, Board* board);
void get_interaction(Player* player, Board* board, Bloc_type type, int version);

#endif