#ifndef LRU_LIST_HXX
#define LRU_LIST_HXX
#include "DoubleLink.h"
/**
 * A class used for mark whether the tail node is removed when insert a new element to the LRU list.
 */
template<class T>
class RemovedTail {
public:
    T value;
    bool tailRemoved;
public:
    /**The constructor of RemovedTail */
    RemovedTail() {
        this->tailRemoved = false;
    }
};

/**
 * The class of LRUList
 */
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

/**
 * The constructor of LRUList, it will init a double list , with a max lenght of `count`.
 */
template<class T>
LRUList<T>::LRUList(unsigned int count) {
    maxCount = count;
}
/**
 * Add a new element to the lru list's head, if current length is equal `maxCount`, the tail node will be removed.
 */
template<class T>
void LRUList<T>::addNewElement(T e,RemovedTail<T> &remvedTail) {
    DNode<T>* node = this->findNode(e);
    if (node != NULL) {
        this->removeNode(node);
        this->insertNodeFirst(node);
    } else {
        if (this->count < this->maxCount) {
            this->insertFirst(e);
        } else {
            remvedTail.tailRemoved = true;
            this->deleteLast(&remvedTail.value);
            this->insertFirst(e);
        }
    }
}

#endif