#include "player.h"



void move_player(Player* player, Dir input, board* board) {
    board->board[player->y][player->x].type = VOID;
    if (input == NORTH && !check_collision(player, player->x, player->y - 1, board)) player->y--;
    if (input == SOUTH && !check_collision(player, player->x, player->y + 1, board)) player->y++;
    if (input == WEST && !check_collision(player, player->x - 1, player->y, board)) player->x--;
    if (input == EAST && !check_collision(player, player->x + 1, player->y, board)) player->x++;
    handle_player_pos(player, board);
    board->board[player->y][player->x].type = PLAYER;
}

bool check_collision(Player* player, int x, int y, board* board) {
    if (board->board[y][x].type != VOID) {
        return true;
    }
    else {
        return false;
    }
}

void handle_player_pos(Player* player, board* board) {
    if (player->x == 0 || player->x == (board->col - 1) || player->y == 0 || player->y == (board->row - 1)) {
        int nb = rand() % NB_CHUNKS;
        assert(nb < NB_CHUNKS && nb >= 0);
        load_chunk(CHUNK_TYPES[nb], board);
    }
    if (player->x == 0) {
        player->x = board->col - 2;
    }
    if (player->x == (board->col - 1)) {
        player->x = 1;
    }
    if (player->y == 0) {
        player->y = board->row - 2;
    }
    if (player->y == (board->row - 1)) {
        player->y = 1;
    }

}

void interaction(Player* player, board* board, Type type) {
    switch (type) {
        case HOUSE:
            load_chunk(CHUNK_TYPES[0], board);
            break;
        case NPC:
            break;
        case CHEST:
            //open_chest();
            break;
    }
}

void interact(Player* player, board* board) {
    assert(player->x > 0 && player->x < board->col - 1 && player->y > 0 && player->y < board->row - 1);
    if (is_interactable(board->board[player->y - 1][player->x].type)) {
        interaction(player, board, board->board[player->y - 1][player->x].type);
    }
    if (is_interactable(board->board[player->y + 1][player->x].type)) {
        interaction(player, board, board->board[player->y + 1][player->x].type);
    }
    if (is_interactable(board->board[player->y][player->x - 1].type)) {
        interaction(player, board, board->board[player->y][player->x - 1].type);
    }
    if (is_interactable(board->board[player->y][player->x + 1].type)) {
        interaction(player, board, board->board[player->y][player->x + 1].type);
    }
}
