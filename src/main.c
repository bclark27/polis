#include <stdio.h>
#include "Widget.h"
#include "World.h"
#include "Population.h"

int main()
{
    Widget_init();
    World* w = World_init();
    NodeID id = World_addNewNode(w, NodeType_Population);
    Population* p = (Population*)World_getNode(w, id);
    World_update(w);
    World_deleteNode(w, id);
    World_update(w);
    
    World_free(w);


    Widget_free();
    printf("HELLO\n");
    return 0;
}