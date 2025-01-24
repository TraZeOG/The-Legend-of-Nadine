#include "main.h"

int main() {
    bool in_menus = true;
    bool changing_menu = true;
    int run = true;
    printf("\033[?25l");
    clear();
    while (run) {
        if (in_menus) {
            printf("pfd je suis un arbre");
            menus(&in_menus, &changing_menu);
        }
        else {
            wprintf(L"🌳rorar je suis un arbre");
            Coord player = {20, 20};
            wchar_t board[28][132] ;
            int ROW = 28;
            int COL = 132;
            game(&in_menus, player, ROW, COL, board);
        }
    }
}