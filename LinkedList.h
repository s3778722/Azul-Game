#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Tile.h"
#include "Node.h"
#include <string>

class LinkedList{
public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor

    int getSize();
    Tile* getTile(int i);
    void clear();

    void addFront(Tile* tile);
    void addBack(Tile* tile);

    Tile* removeFront();
    void removeBack();
    void removeTileAt(int i);
    void removeTile(Tile* tile);
    bool containsTile(Tile* tile);
    std::string toString();

private:
    Node* head;
    Node* tail;
    int count;

};
#endif //LINKEDLIST_H