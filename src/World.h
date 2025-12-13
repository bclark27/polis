#ifndef WORLD_H_
#define WORLD_H_

#include "Node.h"

#include "Population.h"

typedef struct World
{
    unsigned int populationsLength;
    Population* populations;
} World;

World* World_init();
void World_free();

void World_update(World* world);

#endif