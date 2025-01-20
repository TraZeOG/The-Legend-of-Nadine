#ifndef _MENU_H
#define _MENU_H

#include "getch.h"

extern char choix;
typedef enum {
    HOMEPAGE = 1,
    USERNAME = 2,
    DEATH = 3,
} Menu;

void menus();
void draw_menu();

#endif