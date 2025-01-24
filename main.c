#include "main.h"

int main() {
    bool in_menus = true;
    bool changing_menu = true;
    wprintf(L"\033[?25l");
    //clear();
    setlocale(LC_ALL, "");
    wprintf(L"Hello world\n");
    fflush(stdout);
    Coord player = {20, 20};
    board* board = init_board(28, 132); //height and width of the 🥛Caseine terminal
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