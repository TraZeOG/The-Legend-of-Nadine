#ifndef _WORLD_H
#define _WORLD_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


typedef char Type ;
typedef char chunck ;

void save();
void load();
chunck* generate_chunck(Type type);


#endif