#include "World.h"

#include "comm/Common.h"
#include "Population.h"

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
    
}

void World_free()
{

}

void World_update(World* world)
{
    // first run through farms

    // next factories

    // next distrobution

    // next populations
    for (int i = 0; i < world->populationsCount; i++)
    {
        Population* p = &world->populations[i];
        Population_update(p);
    }
}

Node* World_addNewNode(NodeType type)
{
    switch (type)
    {
        case NodeType_Population:
        {
            
            break;
        }
        default:
            break;
    }
}
void World_deleteNode(NodeID id);
Node* World_getNode(NodeID id);

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
        memcpy(newArr, *arr, eleSize * oldSize);
        free(*arr);
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