#include "main.h"

int main() {
    bool in_menus = true;
    int run = true;
    printf("\033[?25l");
    clear();
    while (run) {
        if (in_menus) {
            menus(&in_menus);
        }
        else {
            Coord player = {20, 20};
            char board[28][132] ;
            int ROW = 28;
            int COL = 132;
            game(&in_menus, player, ROW, COL, board);
        }
    }
}