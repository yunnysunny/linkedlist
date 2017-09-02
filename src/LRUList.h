#pragma once
#include "LinkedList.h"
template<class T>
class LRUList<T> :
    public LinkedList<T>
{
private:
    unsigned int maxCount;
public:
    LRUList(unsigned int count);
    void addNewElement(T e);
};

template<class T>
LRUList<T>::LRUList(unsigned int count) {
    maxCount = count;
}
template<class T>
void LRUList<T>::addNewElement(T e) {

}

