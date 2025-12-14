#ifndef NODE_H_
#define NODE_H_

typedef enum NodeType
{
    NodeType_None,
    NodeType_Farm,
    NodeType_Factory,
    NodeType_DC,
    NodeType_Population,
} NodeType;

typedef struct NodeID
{
    NodeType type;
    unsigned int id;
} NodeID;

#define NODE_ID_EQ(a, b)    ((a).id == (b).id && (a).type == (b).type)

typedef struct Node
{
    NodeID id;
    float x;
    float y;
} Node;

#endif