#ifndef _RENDER_H
#define _RENDER_H

#include "player.h"

extern const wchar_t SPRITES[];

void print_board(board* b);
void print_player(Coord* player, board board);

#endif