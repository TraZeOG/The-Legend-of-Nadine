#include "main.h"

int main() {
    bool in_menus = true;
    bool changing_menu = true;
    setlocale(LC_ALL, "");
    wprintf(L"\033[?25l");
    clear();
    Coord player = {20, 20};
    board* board = init_board(28, 80); //height and width of the 🥛Caseine terminal
    int run = true;
    while (run) {
        if (in_menus) {
            menus(&in_menus, &changing_menu);
        }
        else {
            game(&in_menus, player, board);
        }
    }
}