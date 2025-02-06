#include "board.h"


const char* CHUNK_TYPES[] = {
    "chunk_spawn",
    "chunk_village",
    "chunk_forest",
    "chunk_plains",
};

/**
 * @brief Initializes a board with the given number of rows and columns.
 * @param row The number of rows for the board.
 * @param col The number of columns for the board.
 * @return A pointer to the initialized board structure.
 */
board* init_board(int row, int col) {
    clear();
    board* b = malloc(sizeof(board));
    b->board = malloc(sizeof(Bloc*) * row);
    for (int i = 0; i < row; i++) {
        b->board[i] = malloc(sizeof(Bloc) * col);
    }
    b->row = row;
    b->col = col;
    return b;
}

void default_chunk(board* b) {
    for (int i = 0; i < b->row; i++) {
        for (int j = 0; j < b->col; j++) {
            if (i == 0 || i == b->row-1 || j == 0 || j == b->col-1) {
                if ((i == 0 || i == b->row-1) && (j == b->col/2 || j == b->col/2 - 1) || (j == 0 || j == b->col-1) && (i == b->row/2 || i == b->row/2 - 1)) {
                    b->board[i][j].type = VOID;
                }
                else {
                    b->board[i][j].type = WALL;
                }
            }
            else {
                b->board[i][j].type = VOID;
            }
        }
    }
}


void load_chunk(const char* name, board* b) {
    FILE *file;
    char filename[256];
    char line[1024];
    snprintf(filename, sizeof(filename), "chunks/%s.eota", name);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    
    fscanf(file, "%d,%d\n", &b->row, &b->col);
    int type;
    for (int i=0; i < b->row; i++) {
        for (int j=0; j< b->col; j++) {
            fscanf(file, "%d,", &type);
            b->board[i][j].type = type;
        }
        fscanf(file, "\n");
    }
    fclose(file);
    clear();
}

bool is_interactable(Type type) {
    switch (type) {
        case HOUSE:
        case NPC:
        case CHEST:
            return true;
        default:
            return false;
    }
}