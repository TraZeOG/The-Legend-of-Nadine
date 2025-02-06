#ifndef _BOARD_H
#define _BOARD_H

#include "constants.h"
#include <string.h>

#define NB_CHUNKS 3

extern const char* CHUNK_TYPES[];
typedef struct {
    Type type;
    int health;
} Bloc;

typedef struct {
    int row;
    int col;
    Bloc** board;
} board;

board* init_board(int row, int col);
void load_chunk(const char* name, board* board);
void default_chunk(board* board);
bool is_interactable(Type type);


#endif