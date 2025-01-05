#ifndef _GAME_H
#define _GAME_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>


#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define WHITE    "\x1b[0m"

typedef char Chunck ;

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

void game();
void save();
void load();
Chunck* generate_chunck(Type_c type);
void print_chunck(Chunck chunk);

#endif