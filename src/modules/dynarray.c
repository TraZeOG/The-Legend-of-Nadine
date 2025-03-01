#include "dynarray.h"

Map* create_map() {
    Map* map = malloc(sizeof(Map));
    map->chunk = malloc(sizeof(Bloc_type*) * INITIAL_CAPACITY);
    map->x_size = INITIAL_CAPACITY;
    map->y_size = INITIAL_CAPACITY;
    for(size_t i = 0; i < INITIAL_CAPACITY; i++){
        map->chunk[i] = malloc(sizeof(Bloc_type) * INITIAL_CAPACITY);
        for (size_t j = 0; j < INITIAL_CAPACITY; j++) {
            map->chunk[i][j] = rand()%NB_CHUNKS;
        }
    }
    return map;
}

/**
 * @brief Inserts an element into the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index at which to insert the element.
 * @param value The value of the element to insert.
 * @return true if the insertion was successful, false otherwise.
 */
void expand(Map* map, int mult_x, int mult_y, bool reverse) {
    Bloc_type** new_chunks = malloc(sizeof(Bloc_type*) * mult_y * map->y_size);
    for (size_t i = 0; i < map->y_size; i++) {
        new_chunks[i] = malloc(sizeof(Bloc_type) * mult_x * map->x_size);
        int offset_x = 0;
        int offset_y = 0;
        if (reverse) {
            offset_x = map->x_size - 1;
            offset_y = map->y_size - 1;
        }
        for (size_t j = 0; j < map->x_size; j++) {
            new_chunks[i + offset_y][j + offset_x] = map->chunk[i][j];
        }
    }
    free(map->chunk);
    map->chunk = new_chunks;
    map->x_size = mult_x * map->x_size;
    map->y_size = mult_y * map->y_size;
}

/**
 * @brief Frees the memory allocated for the dynamic array.
 * @param array Pointer to the dynamic array to be freed.
 */
void free_map(Map* map) {
    free(map->chunk);
    free(map);
}










