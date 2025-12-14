#ifndef WORLD_H_
#define WORLD_H_

#include "Node.h"

struct Population;

typedef struct World
{
    unsigned int populationsCount;
    unsigned int populationsArraySize;
    struct Population* populations;
} World;

World* World_init();
World* World_clone(World* world);
void World_free(World* world);

void World_update(World* world);
NodeID World_addNewNode(World* world, NodeType type);
void World_deleteNode(World* world, NodeID id);
Node* World_getNode(World* world, NodeID id);

#endif