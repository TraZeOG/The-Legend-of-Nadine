#include "menu.c"
#include "game.c"

int main () {
    bool in_menus = true;
    int run = true;
    while (run) {
        if (in_menus) {
            menus(&in_menus);
        }
        else {
            game(&in_menus);
        }
    }
}