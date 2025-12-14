#include "World.h"

#include "comm/Common.h"
#include "Population.h"

////////////
//  VARS  //
////////////

static unsigned int idCounter = 0;

/////////////////
//  FUNC DEFS  //
/////////////////

void minElementHelper(void** arr, unsigned int eleSize, unsigned int newMinLen, unsigned int* currArrLen);
void removeElementHelper(void* arr, unsigned int eleSize, unsigned int idx, unsigned int* count);


////////////////////
//  PUBLIC FUNCS  //
////////////////////

World* World_init()
{
    World* w = calloc(1, sizeof(World));
    return w;
}

World* World_clone(World* world)
{
    World* clone = World_init();

    clone->populationsCount = world->populationsCount;
    clone->populationsArraySize = world->populationsArraySize;
    if (world->populations)
    {
        clone->populations = malloc(sizeof(world->populationsArraySize) * sizeof(Population));
        memcpy(clone->populations, world->populations, sizeof(Population) * world->populationsCount);
    }

    return clone;
}

void World_free(World* world)
{
    if (world->populations) free(world->populations);
    free(world);
}

void World_update(World* world)
{
    // first run through farms

    // next factories

    // next distrobution

    // next populations
    printf("Updating %d populations needs...\n", world->populationsCount);
    for (int i = 0; i < world->populationsCount; i++)
    {
        Population* p = &world->populations[i];
        Population_update(world, p, PopulationUpdateStep_Needs);
    }

    printf("Updating %d populations wants and sizes...\n", world->populationsCount);
    for (int i = 0; i < world->populationsCount; i++)
    {
        Population* p = &world->populations[i];
        Population_update(world, p, PopulationUpdateStep_Wants);
        Population_update(world, p, PopulationUpdateStep_Size);
    }
}

NodeID World_addNewNode(World* world, NodeType type)
{
    switch (type)
    {
        case NodeType_Population:
        {
            minElementHelper((void**)&world->populations, sizeof(Population), world->populationsCount + 1, &world->populationsArraySize);
            NodeID id = {
                .id = idCounter++,
                .type = NodeType_Population,
            };
            Population* newPop = &world->populations[world->populationsCount++];
            Population_initInPlace(newPop);
            newPop->node.id = id;
            return id;
        }
        default:
            return (NodeID){.id=0, .type=0 };
    }
}
void World_deleteNode(World* world, NodeID id)
{
    switch (id.type)
    {
        case NodeType_Population:
        {
            for (int i = 0; i < world->populationsCount; i++)
            {
                Population* p = &world->populations[i];
                if (NODE_ID_EQ(p->node.id, id))
                {
                    removeElementHelper(world->populations, sizeof(Population), i, &world->populationsCount);
                    return;
                }
            }
            break;
        }
        default:
            break;
    }
}

Node* World_getNode(World* world, NodeID id)
{
    switch (id.type)
    {
        case NodeType_Population:
        {
            for (int i = 0; i < world->populationsCount; i++)
            {
                Population* p = &world->populations[i];
                if (NODE_ID_EQ(p->node.id, id))
                    return (Node*)p;
            }
            break;
        }
        default:
            break;
    }

    return NULL;
}

//////////////////
//  PRIV FUNCS  //
//////////////////

void minElementHelper(void** arr, unsigned int eleSize, unsigned int newMinLen, unsigned int* currArrLen)
{
    if (newMinLen >= *currArrLen)
    {
        unsigned int oldSize = *currArrLen;
        unsigned int newSize = MAX(*currArrLen * 2, newMinLen);
        void* newArr = malloc(eleSize * newSize);
        if (*arr)
        {
            if (oldSize)
            {
                memcpy(newArr, *arr, eleSize * oldSize);
            }
            free(*arr);
        }
        *arr = newArr;
        *currArrLen = newSize;
    }
}

void removeElementHelper(void* arr, unsigned int eleSize, unsigned int idx, unsigned int* count)
{
    if (!arr || !count) return;
    if (idx >= *count) return;

    unsigned char* base = (unsigned char*)arr;
    unsigned int elements_after = (*count - idx - 1);
    if (elements_after > 0) {
        memmove(base + idx * eleSize,
                base + (idx + 1) * eleSize,
                elements_after * eleSize);
    }

    (*count)--;
}