#ifndef _BOARD_H
#define _BOARD_H

#include "constants.h"
#include "dynarray.h"
#include <string.h>


extern const char* CHUNK_TYPES[];
extern const char* CHUNK_HOUSE[];
typedef struct {
    Type type;
    int health;
} Bloc;

typedef struct {
    int row;
    int col;
    Board_type type;
    Bloc** board;
} Board;

Board* init_board(int row, int col);
void load_chunk(const char* name, Board* board);
void default_chunk(Board* board);
bool is_interactable(Type type);


#endif