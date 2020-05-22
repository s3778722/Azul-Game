#ifndef NODE_H
#define NODE_H
#include "Tile.h"

class Node{
public:
    //constructor
    Node(Tile* tile, Node* next); 
    // copy constructor
    Node(Node& other);
    // destructor
    ~Node(); 

    //the tile this node represents
    Tile* tile;
    //reference to the next node in the linked list.
    Node* next;
};
#endif //NODE_H