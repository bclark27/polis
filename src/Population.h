#ifndef POPULATION_H_
#define POPULATION_H_

#include "Node.h"

#define POPULATION_DEATH_RATE (0.01)

typedef struct Population
{
    Node node;
    unsigned int size;
    float needsSatisfaction; // 1=fully satisfied
    float wantsSatisfaction; // 1=fully satisfied
} Population;

#endif