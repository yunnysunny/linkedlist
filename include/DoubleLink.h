#ifndef DOUBLE_LINK_HXX
#define DOUBLE_LINK_HXX

#include <iostream>
using namespace std;
/**
* The class of DNode, used it for DoubleLink
*/
template<class T>
struct DNode
{
public:
    T value;
    DNode *prev;
    DNode *next;
public:
    DNode() { }
    DNode(T t, DNode *prev, DNode *next) {
        this->value = t;
        this->prev = prev;
        this->next = next;
    }
};
/**
* The class of DoubleLink\n
*\n
*    ```
*     |----|--->|----|
*     |tail|    |head|
*     |----|<---|----|
*   ```
*\n
*/
template<class T>
class DoubleLink
{
public:
    DoubleLink();
    ~DoubleLink();

    int size();
    bool isEmpty();

    T get(unsigned int index);
    T getFirst();
    T getLast();
    DNode<T>* findNode(T t);
    void traversal();//traverse and print

    int insert(unsigned int index, T t);
    int insertFirst(T t);
    int appendLast(T t);

    int del(unsigned int index,T* value);
    int del(unsigned int index);
    int deleteFirst(T* value);
    int deleteFirst();
    int deleteLast(T* value);
    int deleteLast();

protected:
    unsigned int count;
    DNode<T> *phead;
    int removeNode(DNode<T>* node);
    //int removeNode();
    int insertNodeFirst(DNode<T>* node);
    //int insertNodeFirst();
private:
    DNode<T> *getNode(unsigned int index);
};
/**
* The constructor
*/
template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
    // create the head, attention: this is no data in head.
    phead = new DNode<T>();
    phead->prev = phead->next = phead;
    // 
    //count = 0;
}

// the destructor
template<class T>
DoubleLink<T>::~DoubleLink()
{
    // delete all nodes
    DNode<T>* ptmp;
    DNode<T>* pnode = phead->next;
    while (pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode->next;
        delete ptmp;
    }

    // delete the head
    delete phead;
    phead = NULL;
}
/**
* Find a node by a T element
*/
template<class T>
DNode<T>* DoubleLink<T>::findNode(T t) {
    DNode<T>* pnode = phead->next;
    DNode<T>* findNode = NULL;
    while (pnode != phead) {
        if (pnode->value == t) {
            findNode = pnode;
            break;
        }
        pnode = pnode->next;
    }
    return findNode;
}
/**
* traverse all the nodes
*/
template<class T>
void DoubleLink<T>::traversal() {
    DNode<T>* pnode = phead->next;
    while (pnode != phead)
    {
        cout << pnode->value << ends;
        pnode = pnode->next;
    }
    cout << endl;
}

/**
* Get the count of nodes
*/
template<class T>
int DoubleLink<T>::size()
{
    return count;
}

/**
* Check if the list is empty.
*/
template<class T>
bool DoubleLink<T>::isEmpty()
{
    return count == 0;
}

/**
* Get the node by index.
*/
template<class T>
DNode<T>* DoubleLink<T>::getNode(unsigned int index)
{
    // check if the paramerter is valid
    if (index<0 || index >= count)
    {
        cout << "get node failed! the index in out of bound!" << endl;
        return NULL;
    }
    if (index == 0) {
        return phead->next;
    }
    if (index == count - 1) {
        return phead->prev;
    }

    // top half, search from begin
    if (index <= count / 2)
    {
        unsigned int i = 0;
        DNode<T>* pindex = phead->next;
        while (i++ < index) {//i == index-1, end
            pindex = pindex->next;
        }

        return pindex;
    }

    // bottom half, search from tail
    int j = 0;
    int rindex = count - index - 1;
    DNode<T>* prindex = phead->prev;//the tail node
    while (j++ < rindex) {
        prindex = prindex->prev;
    }

    return prindex;
}

/**
* Get the value of the `index` node
*/
template<class T>
T DoubleLink<T>::get(unsigned int index)
{
    return getNode(index)->value;
}

/**
* Get first node's value
*/
template<class T>
T DoubleLink<T>::getFirst()
{
    return getNode(0)->value;
}

/**
* Get the last node's value
*/
template<class T>
T DoubleLink<T>::getLast()
{
    return getNode(count - 1)->value;
}

/**
* Insert the element to the front of index's node.
*/ 
template<class T>
int DoubleLink<T>::insert(unsigned int index, T t)
{
    if (index == 0)
        return insertFirst(t);

    DNode<T>* pindex = getNode(index);
    DNode<T>* pnode = new DNode<T>(t, pindex->prev, pindex);
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;

    return 0;
}
/**
* Insert the node to the first.
*/
template<class T>
int DoubleLink<T>::insertNodeFirst(DNode<T>* pnode) {
    phead->next->prev = pnode;
    phead->next = pnode;
    return 0;
}

/**
* Create a node and insert it to the first
*/
template<class T>
int DoubleLink<T>::insertFirst(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
    insertNodeFirst(pnode);
    count++;

    return 0;
}

/**
* Create a node and insert it to the tail
*/ 
template<class T>
int DoubleLink<T>::appendLast(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
    phead->prev->next = pnode;
    phead->prev = pnode;
    count++;

    return 0;
}

/**
* Remove an exist node
*/ 
template<class T>
int DoubleLink<T>::removeNode(DNode<T>* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    count--;
    return 0;
}

/**
* Remove the index's node, and copy the value to the porint of `value`.
*/ 
template<class T>
int DoubleLink<T>::del(unsigned int index,T* value)
{
    if (index<0 || index >= count)
    {
        cout << "get node failed! the index in out of bound!" << endl;
        return 1;
    }
    DNode<T>* pindex = getNode(index);
    if (value != NULL) {
        *value = pindex->value;
    }
    removeNode(pindex);
    delete pindex;
    return 0;
}

/**
* Remove the index's node.
*/ 
template<class T>
int DoubleLink<T>::del(unsigned int index)
{
    return del(index, NULL);
}

/**
* Remove the first node, and save its value to `value`.
*/
template<class T>
int DoubleLink<T>::deleteFirst(T* value)
{
    return del(0,value);
}

/**
* Remove the first node.
*/
template<class T>
int DoubleLink<T>::deleteFirst()
{
    return del(0, NULL);
}

/**
* Remove the last node, and save its value to `value`.
*/ 
template<class T>
int DoubleLink<T>::deleteLast(T* value)
{
    return del(count - 1,value);
}

/**
* Remove the last node.
*/
template<class T>
int DoubleLink<T>::deleteLast()
{
    return del(count - 1, NULL);
}

#endif
