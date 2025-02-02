#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int type;
    bool loaded;
} Chunck;

typedef struct {
    Chunck** chunck;
    size_t capacity;
} Map;

typedef struct {
    int x;
    int y;
} Cos;

Map* create_map();
size_t len(Map* map);
int get_chunck(Map* map, Cos* cos);
void expand(Map* map);
void free(Map* map);

#endif