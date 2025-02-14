#ifndef _MENU_H
#define _MENU_H

#include "getch.h"
#include "constants.h"


extern char choix;

void menus(bool* in_menus, bool* changing_menu);
void draw_menu(Menu menu);

#endif