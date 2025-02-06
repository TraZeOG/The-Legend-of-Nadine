#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#define INITIAL_CAPACITY 10

typedef struct {
    int type;
    bool loaded;
} Chunck;

typedef struct {
    Chunck** chunck;
    size_t capacity;
} Map;

Map* create_map();
size_t len(Map* map);
int get_chunck(Map* map, Coord* cos);
void expand(Map* map);
void free(Map* map);

#endif