#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Tile.h"
#include "Node.h"

class LinkedList{
public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor

    int getSize();
    Tile* LinkedList::get(int i);
    void clear();

    void addFront(Tile* tile);
    void addBack(Tile* tile);

    void removeFront();
    void removeBack();
    void removeTile(Tile* tile);
    std::string toString();

private:
    Node* head;
    Node* tail;
    int count;

};
#endif //LINKEDLIST_H