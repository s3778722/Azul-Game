#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Tile.h"
#include "Node.h"
#include <string>

class LinkedList{
public:
    //constructor
    LinkedList(); 
    //destructor
    ~LinkedList(); 

    // get the size
    int getSize();
    // get the tile at the given position in the linked list
    Tile* getTile(int i);
    // clear/empty the linked list
    void clear();

    // adds tile to the front of the linked list
    void addFront(Tile* tile);
    //adds tile to the back of the linked list
    void addBack(Tile* tile);

    // removes tile at the very front of the linked list
    Tile* removeFront();
    // removes tile at the very back of the linked list
    void removeBack();
    //removes the tile at the given index
    void removeTileAt(int i);
    // removes tile denoted, first found is removed
    void removeTile(Tile* tile);
    // checks if a tile is in the linked list
    bool containsTile(Tile* tile);
    // to string version of the linked list
    std::string toString();

private:
    Node* head;
    Node* tail;
    int count;

};
#endif //LINKEDLIST_H