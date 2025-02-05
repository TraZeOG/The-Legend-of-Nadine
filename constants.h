#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <wchar.h>
#include <locale.h>
#define clear() wprintf(L"\033[H\033[J")

#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define WHITE    "\x1b[0m"

typedef enum {
    HOMEPAGE = 1,
    USERNAME = 2,
    DEATH = 3,
} Menu;

extern wchar_t SPRITES[];

typedef enum {
    VOID = 0,
    PLAYER = 1,
    WALL = 2,
    LOOT = 3,
    ENEMY = 4,
    HOUSE = 5,
    GATE = 6,
    NPC = 7,
    TREE = 8,
} Type;

typedef enum { //names speak for themselves
    SPAWN = 0,
    NORMAL = 1,
    CHEST = 2,
    MAZE = 3,
    BOSS = 4
} Type_c;

typedef enum {
    KNIGHT = 1,
    SLIME = 2,
    SPIDER = 3
} Enemy;

typedef enum {
    NORTH = 'z',
    EAST = 'd',
    SOUTH = 's',
    WEST = 'q'
} Dir;


#endif