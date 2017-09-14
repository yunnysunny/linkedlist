#ifndef LRU_LIST_HXX
#define LRU_LIST_HXX
#include "DoubleLink.h"

template<class T>
class RemovedTail {
public:
    T value;
    bool tailRemoved;
public:
    RemovedTail() {
        this->tailRemoved = false;
    }
};

template<class T>
class LRUList :
    public DoubleLink<T>
{
private:
    unsigned int maxCount;
public:
    LRUList(unsigned int count);
    void addNewElement(T e, RemovedTail<T> &remvedTail);
};

template<class T>
LRUList<T>::LRUList(unsigned int count) {
    maxCount = count;
}
template<class T>
void LRUList<T>::addNewElement(T e,RemovedTail<T> &remvedTail) {
    DNode<T>* node = findNode(e);
    if (node != NULL) {
        removeNode(node);
        insertNodeFirst(node);
    } else {
        if (this->count < this->maxCount) {
            insertFirst(e);
        } else {
            remvedTail.tailRemoved = true;
            deleteLast(&remvedTail.value);
            insertFirst(e);
        }
    }
}

#endif