#include <dynarray.h>

/**
 * @brief Initializes a dynamic array.
 * @param array Pointer to the dynamic array to be initialized.
 */

Chunck* create_chunck(int type, int x, int y) {
    Chunck* chunck = malloc(sizeof(Chunck));
    chunck->loaded = false;
    chunck->type = type;
    chunck->x = x;
    chunck->y = y;
}

Map* create_map() {
    Map* map = malloc(sizeof(Map));
    map->chunck = malloc(INITIAL_CAPACITY * sizeof(Chunck**));
    map->capacity = INITIAL_CAPACITY;
    for(size_t i = 0; i < INITIAL_CAPACITY; i++){
        array->chunck[i] = malloc(sizeof(Chunck*));
        for (size_t j = 0; j < INITIAL_CAPACITY; j++) {
            array->chunck[i][j] = create_chunck(rand()%NB_TYPES, i, j);
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
Chunck* get_chunck(Map* map, Cos* cos) {
    return &(map->chunck[cos->x][cos->y]);
}

/**
 * @brief Inserts an element into the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index at which to insert the element.
 * @param value The value of the element to insert.
 * @return true if the insertion was successful, false otherwise.
 */
void expand(Map* map) {
    Chunck** new_chuncks = malloc(sizeof(Chunck**) * 2 * map->capacity);
    for (size_t i = 0; i < map->capacity; i++) {
        new_chuncks[i] = malloc(sizeof(Chunck*) * 2 * map->capacity);
        for (size_t j = 0; j < map->capacity; j++) {
            new_chuncks[i][j] = map->chunck[i][j];
        }
    }
    free(map->chunck);
    map->chunck = new_chuncks;
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










