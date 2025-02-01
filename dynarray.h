#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynArray;

void create(DynArray *array);
size_t length(DynArray *array);
int get(DynArray *array, size_t index);
bool insert(DynArray *array, size_t index, int value);
bool remove(DynArray *array, size_t index);
void free(DynArray *array);

#endif