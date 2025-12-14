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
void World_free();

void World_update(World* world);
Node* World_addNewNode(NodeType type);
void World_deleteNode(NodeID id);
Node* World_getNode(NodeID id);

#endif