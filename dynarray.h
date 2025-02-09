#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#define INITIAL_CAPACITY 10
#include "constants.h"

typedef struct {
    Type** chunk;
    int x_size;
    int y_size;
} Map;

Map* create_map();
void expand(Map* map, int mult_x, int mult_y, bool reverse);
void free_map(Map* map);

#endif