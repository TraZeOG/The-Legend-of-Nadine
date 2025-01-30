#include "board.h"



/**
 * @brief Initializes a board with the given number of rows and columns.
 * @param row The number of rows for the board.
 * @param col The number of columns for the board.
 * @return A pointer to the initialized board structure.
 */
board* init_board(int row, int col) {
    clear();
    board* b = malloc(sizeof(board));
    b->board = malloc(sizeof(Bloc) * row);
    for (int i = 0; i < row; i++) {
        b->board[i] = malloc(sizeof(Bloc) * col);
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == col-1) {
                if ((i == 0 || i == row-1) && (j == col/2 || j == col/2 - 1) || (j == 0 || j == col-1) && (i == row/2 || i == row/2 - 1)) {
                    b->board[i][j].type = GATE;
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
    b->row = row;
    b->col = col;
    return b;
}

void save_chunck(board* board, char* name) {
    FILE *file;
    char filename[256];
    snprintf(filename, sizeof(filename), "%s.eota", name);
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    for (int i = 0; i < board->row; i++) {
        for (int j = 0; j < board->col; j++) {
            Bloc bloc = board->board[i][j];
            snprintf(line, sizeof(line), "%d %d %d\n", i, j, bloc.type);
            fputs(line, file);
        }
    }
    fclose(file);
}

board* load_chunck(char* name) {
    FILE *file;
    char filename[256];
    snprintf(filename, sizeof(filename), "%s.eota", name);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int row, col;
    fscanf(file, "%d %d", &row, &col);
    board* b = init_board(row, col);

    int i, j, type;
    while (fscanf(file, "%d %d %d", &i, &j, &type) != EOF) {
        b->board[i][j].type = type;
    }

    fclose(file);
    return b;
}