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
    int x;
    int y;
} Chunck;

typedef struct {
    Chunck** chunck;
    size_t capacity;
} Map;

void create(Map *array);
size_t length(Map *array);
int get(Map *array, size_t index);
bool insert(Map *array, size_t index, int value);
bool remove(Map *array, size_t index);
void free(Map *array);

#endif