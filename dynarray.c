#include <dynarray.h>



/**
 * @brief Initializes a dynamic array.
 * @param array Pointer to the dynamic array to be initialized.
 */
void create(DynArray *array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

/**
 * @brief Returns the length of the dynamic array.
 * @param array Pointer to the dynamic array.
 * @return The number of elements in the dynamic array.
 */
size_t length(DynArray *array) {
    return array->size;
}

/**
 * @brief Retrieves an element from the dynamic array.
 * @param array Pointer to the dynamic array.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or -1 if the index is out of bounds.
 */
int get(DynArray *array, size_t index) {
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
bool insert(DynArray *array, size_t index, int value) {
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
bool remove(DynArray *array, size_t index) {
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
void free(DynArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}










