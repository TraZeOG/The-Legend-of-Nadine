#include "player.h"



void move_player(Player* player, Dir input, board* board) {
    board->board[player->y][player->x].sprite = SPRITE_VOID;
    if (input == NORTH && !check_collision(player, player->x, player->y - 1, board)) player->y--;
    if (input == SOUTH && !check_collision(player, player->x, player->y + 1, board)) player->y++;
    if (input == WEST && !check_collision(player, player->x - 1, player->y, board)) player->x--;
    if (input == EAST && !check_collision(player, player->x + 1, player->y, board)) player->x++;
    board->board[player->y][player->x].sprite = SPRITE_PLAYER;
}

bool check_collision(Player* player, int x, int y, board* board) {
    if (board->board[y][x].type != VOID) {
        return true;
    }
    else {
        return false;
    }
}
