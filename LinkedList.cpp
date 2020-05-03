#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

LinkedList::~LinkedList(){
    this->clear();
}

void LinkedList::clear(){
    Node* current = head;

    while(current != nullptr){
        Node* nextCurrent = current->next;
        delete current;
        current = nextCurrent;
    }
}

int LinkedList::getSize(){
    /*
    Node* current = head;
    while(current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
    */
   return this->count;
}

//return the index of a tile
Tile* LinkedList::getTile(int i){
    Node* current = head;
    Tile* returnValue = nullptr;
    if (i >= 0 && i < getSize()){
        for(int j = 0; j < i; j++){
            current = current->next;
        }
        returnValue = current->tile;
    }
    else{
        throw std::out_of_range("Linked List get - index out of range");
    }
    return returnValue;
}

void LinkedList::addFront(Tile* tile){
    Node* toAdd = new Node(tile, nullptr);
    Node* toAddHead = new Node(tile, this->head);
    if (head == nullptr){
        head = toAdd;
        tail = toAdd;
    }else{
        head = toAddHead;
    }
    count++;
}

void LinkedList::addBack(Tile* tile){
    Node* toAdd = new Node(tile, nullptr);
    if (head == nullptr){
        head = toAdd;
        tail = toAdd;
    }else{
        tail->next = toAdd;
        tail = toAdd;
    }
    count++;
}

void LinkedList::removeFront(){
    if (head != nullptr){
        Node* toRemove = head;
        head = toRemove->next;
        delete toRemove;
        count--; 
    }
}

void LinkedList::removeBack(){
    if (head != nullptr){
        Node* toRemove = head;
        delete tail;
        while (toRemove->next != nullptr)
        {
            toRemove = toRemove->next;
        }
        tail = toRemove;
        count--;
    }
}
void LinkedList::removeTileAt(int i)
{  
    if (i == 0){
       removeFront;
    }
    else if (i == this->getSize()-1){
        removeBack;
    }
    else{
        Node* node = this->head;
        Node* temp = nullptr;
        for(int j = 0; j < i; j++){
            temp = node;
            node = node->next;
        }
        temp->next = node->next;
        delete node;
        --count;
    }
}

void LinkedList::removeTile(Tile* tile) {
    if (head != nullptr) {
        Node* tileToRemove = head;
        while (tileToRemove != nullptr && !(tileToRemove->tile->matchTile(tile))){
            tileToRemove = tileToRemove->next;
        }
        if (tileToRemove != nullptr) {
            delete tileToRemove;
            count--;
        }
    }
}
bool LinkedList::containsTile(Tile* tile){
    bool contained = false;
    Node* tileToCheck = head;

    while(tileToCheck != nullptr && !contained){
        if(tileToCheck->tile->matchTile(tile)){
            contained = true;
        }
        tileToCheck = tileToCheck->next;
    }
    return contained;
}

std::string LinkedList::toString(){
    //TODO
}