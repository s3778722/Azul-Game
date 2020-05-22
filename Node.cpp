#include "Node.h"

Node::Node(Tile* tile, Node* next) //constructor
{
   this->tile = tile;
   this->next = next;
}

//copy constructor
Node::Node(Node& other) :
    Node(other.tile,other.next){}

Node::~Node() //destructor
{
    delete tile;
}