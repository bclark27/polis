#include "Widget.h"

/////////////
//  TYPES  //
/////////////

typedef struct Inventory
{
    float currentWeight;
    float maxWeight;
    float widgets[WIDGET_TYPE_COUNT];
} Inventory;