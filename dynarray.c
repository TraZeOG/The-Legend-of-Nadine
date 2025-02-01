#include <dynarray.h>


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
size_t length(Map* map) {
    return array->size;
}

/**
 * @brief Retrieves an element from the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or -1 if the index is out of bounds.
 */
int get(Map* map, size_t index) {
    if (index >= array->size) {
        return -1;
    }
    return array->data[index];
}

/**
 * @brief Inserts an element into the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index at which to insert the element.
 * @param value The value of the element to insert.
 * @return true if the insertion was successful, false otherwise.
 */
bool insert(Map* map, size_t index, int value) {
    if (index > array->size) {
        return false;
    }
    if (array->size == array->capacity) {
        size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        int *new_data = realloc(array->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            return false;
        }
        array->data = new_data;
        array->capacity = new_capacity;
    }
    for (size_t i = array->size; i > index; --i) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = value;
    array->size++;
    return true;
}

/**
 * @brief Removes an element from the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index of the element to remove.
 * @return true if the removal was successful, false otherwise.
 */
bool remove(Map* map, size_t index) {
    if (index >= array->size) {
        return false;
    }
    for (size_t i = index; i < array->size - 1; ++i) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    return true;
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










