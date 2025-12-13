#ifndef NODE_H_
#define NODE_H_

typedef enum NodeType
{
    NodeType_Farm,
    NodeType_Factory,
    NodeType_DC,
    NodeType_Population,
} NodeType;

typedef struct NodeID
{
    unsigned int id;
    NodeType type;
} NodeID;

#define NODE_ID_EQ(a, b)    ((a).id == (b).id && (a).type == (b).type)

typedef struct Node
{
    NodeID id;
    float x;
    float y;
} Node;

#endif