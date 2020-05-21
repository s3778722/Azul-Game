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

    Tile* tile;
    Node* next;
};
#endif //NODE_H