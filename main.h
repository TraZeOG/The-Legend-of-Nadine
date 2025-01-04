#ifndef _MAIN_H
#define _MAIN_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef enum {
    PSEUDO = 1,
    HOMEPAGE = 2,
    CHARACTER = 3,
    SCORES = 4,
    GAME = 0,
    DEATH = -1,
    PAUSE = -2
} Menu;

#endif