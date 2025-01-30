#include "render.h"



const wchar_t SPRITES[] = {
    L' ',         // SPRITE_VOID
    L'\U0001F9D9', // SPRITE_PLAYER 🧙
    L'\U0001F9F1', // SPRITE_WALL 🧱
    L'\U0001F9DF', // SPRITE_ENEMY 🧟
    L'\U0001F48E', // SPRITE_LOOT 💎
    L'\U0001F6AA',  // SPRITE_GATE 🚪
};

/**
 * @brief Prints the board to the console.
 * @param b A pointer to the board structure to be printed.
 */
void print_board(board* b) {
    setlocale(LC_ALL, "");
    wprintf(L"\033[H");
    for (int i = 0; i < b->row; i++) {
        for (int j = 0; j < b->col; j++) {
            if (b->board[i][j].type == VOID) {
                wprintf(L"  ");
            } else {
                wprintf(L"%lc", SPRITES[b->board[i][j].type]);
            }
        }
        wprintf(L"\n");
    }
    fflush(stdout); 
}