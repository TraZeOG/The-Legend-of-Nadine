#include "main.h"

int main() {
    bool in_menus = true;
    bool changing_menu = true;
    printf("\033[?25l");
    clear();
    int run = true;
    while (run) {
        if (in_menus) {
            menus(&in_menus, &changing_menu);
        }
        else {
            Coord player = {20, 20};
            board board = init_board(28, 132); //height and width of the caseine terminal
            game(&in_menus, player, board);
        }
    }
}