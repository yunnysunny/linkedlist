#ifndef LRU_LIST_HXX
#define LRU_LIST_HXX
#include "DoubleLink.h"
template<class T>
class LRUList :
    public DoubleLink<T>
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
    DNode<T>* node = find_node(e);
    if (node != NULL) {
        remove_node(node);
        insert_node_first(node);
    } else {
        if (this->count < this->maxCount) {
            insert_first(e);
        } else {
            delete_last();
            insert_first(e);
        }
    }
}

#endif