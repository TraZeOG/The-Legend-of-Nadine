#include "player.h"



void move_player(Player* player, Dir input, Board* board, Map* map) {
    board->board[player->y][player->x].type = VOID;
    if (input == NORTH && !check_collision(player, player->x, player->y - 1, board)) player->y--;
    if (input == SOUTH && !check_collision(player, player->x, player->y + 1, board)) player->y++;
    if (input == WEST && !check_collision(player, player->x - 1, player->y, board)) player->x--;
    if (input == EAST && !check_collision(player, player->x + 1, player->y, board)) player->x++;
    handle_player_pos(player, board, map);
    put_player_on_board(board, player);
}

void put_player_on_board(Board* board, Player* player) {
    board->board[player->y][player->x].type = PLAYER;
}

bool check_collision(Player* player, int x, int y, Board* board) {
    if (board->board[y][x].type != VOID) {
        return true;
    }
    else {
        return false;
    }
}

void handle_map(Player* player, Map* map) {
    if (player->chunk_x < 0) {
        expand(map, 2, 1, true);
    }
    if (player->chunk_y < 0) {
        expand(map, 1, 2, true);
    }
    if (player->chunk_x >= map->x_size) {
        expand(map, 2, 1, false);
    }
    if (player->chunk_y >= map->y_size) {
        expand(map, 1, 2, false);
    }
}

void handle_player_pos(Player* player, Board* board, Map* map) {
    if (player->x == 0) {
        player->chunk_x--;
        player->x = board->col - 2;
        handle_map(player, map);
        load_chunk(CHUNK_TYPES[map->chunk[player->chunk_x][player->chunk_y]], board);
    }
    if (player->x == board->col - 1) {
        player->chunk_x++;
        player->x = 1;
        handle_map(player, map);
        load_chunk(CHUNK_TYPES[map->chunk[player->chunk_x][player->chunk_y]], board);
    }
    if (player->y == 0) {
        player->chunk_y--;
        player->y = board->row - 2;
        handle_map(player, map);
        load_chunk(CHUNK_TYPES[map->chunk[player->chunk_x][player->chunk_y]], board);
    }
    if (player->y == board->row - 1) {
        player->chunk_y++;
        player->y = 1;
        handle_map(player, map);
        load_chunk(CHUNK_TYPES[map->chunk[player->chunk_x][player->chunk_y]], board);
    }
}

void interaction(Player* player, Board* board, Type type) {
    switch (type) {
        case HOUSE:
            player->y = board->row - 2;
            player->x = board->col / 2;
            load_chunk(CHUNK_HOUSE[0], board);
            put_player_on_board(board, player);
            break;
        case NPC:
            break;
        case CHEST:
            //open_chest();
            break;
    }
}

void interact(Player* player, Board* board) {
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
