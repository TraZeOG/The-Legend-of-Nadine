#include <dynarray.h>

/**
 * @brief Initializes a dynamic array.
 * @param array Pointer to the dynamic array to be initialized.
 */

Chunk* create_chunk(int type, int x, int y) {
    Chunk* chunk = malloc(sizeof(Chunk));
    chunk->loaded = false;
    chunk->type = type;
    chunk->x = x;
    chunk->y = y;
}

Map* create_map() {
    Map* map = malloc(sizeof(Map));
    map->chunk = malloc(INITIAL_CAPACITY * sizeof(Chunk**));
    map->capacity = INITIAL_CAPACITY;
    for(size_t i = 0; i < INITIAL_CAPACITY; i++){
        array->chunk[i] = malloc(sizeof(Chunk*));
        for (size_t j = 0; j < INITIAL_CAPACITY; j++) {
            array->chunk[i][j] = create_chunk(rand()%NB_TYPES, i, j);
        }
    }
    return map;
}

/**
 * @brief Returns the length of the dynamic array.
 * @param array Pointer to the dynamic array.
 * @return The number of elements in the dynamic array.
 */
size_t len(Map* map) {
    return map->capacity;
}

/**
 * @brief Retrieves an element from the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or -1 if the index is out of bounds.
 */
Chunk* get_chunk(Map* map, Cos* cos) {
    return &(map->chunk[cos->x][cos->y]);
}

/**
 * @brief Inserts an element into the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index at which to insert the element.
 * @param value The value of the element to insert.
 * @return true if the insertion was successful, false otherwise.
 */
void expand(Map* map) {
    Chunk** new_chunks = malloc(sizeof(Chunk**) * 2 * map->capacity);
    for (size_t i = 0; i < map->capacity; i++) {
        new_chunks[i] = malloc(sizeof(Chunk*) * 2 * map->capacity);
        for (size_t j = 0; j < map->capacity; j++) {
            new_chunks[i][j] = map->chunk[i][j];
        }
    }
    free(map->chunk);
    map->chunk = new_chunks;
    map->capacity *= 2;
}

/**
 * @brief Frees the memory allocated for the dynamic array.
 * @param array Pointer to the dynamic array to be freed.
 */
void free(Map* map) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}










