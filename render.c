#include "render.h"


wchar_t SPRITES[] = {
    L' ',         // SPRITE_VOID
    L'\U0001F9D9', // SPRITE_PLAYER 🧙
    L'\U0001F9F1', // SPRITE_WALL 🧱
    L'\U0001F48E', // SPRITE_LOOT 💎
    L'\U0001F9DF', // SPRITE_ENEMY 🧟
    L'\U0001F3E0', // SPRITE_HOUSE 🏠
    L'\U0001F6AA',  // SPRITE_GATE 🚪
    L'\U0001F9D1', // SPRITE_NPC 🧑
    L'\U0001F333', // SPRITE_TREE 🌳
    L'\U0001F381', // SPRITE_CHEST 🎁
    L'\U0001F47B', // SPRITE_GHOST 👻
    L'\U0001F335', // SPRITE_CACTUS 🌵
    L'\U0001F525', // SPRITE_FIRE 🔥
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