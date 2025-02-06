#ifndef _GAME_H
#define _GAME_H

#include "render.h"
#include "getch.h"


void game (bool* in_menus, Player* player, board* board);
void save();
void load();

#endif