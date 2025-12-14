#ifndef POPULATION_H_
#define POPULATION_H_

#include "Node.h"

#define POPULATION_DEATH_RATE (0.01)

typedef enum PopulationUpdateStep
{
    PopulationUpdateStep_Needs,
    PopulationUpdateStep_Wants,
    PopulationUpdateStep_Size,
} PopulationUpdateStep;

typedef struct Population
{
    Node node;
    unsigned int size;
    float needsSatisfaction; // 1=fully satisfied
    float wantsSatisfaction; // 1=fully satisfied
} Population;

struct World;

void Population_initInPlace(Population* p);
void Population_update(struct World* w, Population* p, PopulationUpdateStep step);

#endif