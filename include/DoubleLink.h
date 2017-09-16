﻿#ifndef DOUBLE_LINK_HXX
#define DOUBLE_LINK_HXX

#include <iostream>
using namespace std;

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
|----|--->|----|
|tail|    |head|
|----|<---|----|
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
    void traversal();//遍历整个链表并打印

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

template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
    // 创建“表头”。注意：表头没有存储数据！
    phead = new DNode<T>();
    phead->prev = phead->next = phead;
    // 设置链表计数为0
    //count = 0;
}

// 析构函数
template<class T>
DoubleLink<T>::~DoubleLink()
{
    // 删除所有的节点
    DNode<T>* ptmp;
    DNode<T>* pnode = phead->next;
    while (pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode->next;
        delete ptmp;
    }

    // 删除"表头"
    delete phead;
    phead = NULL;
}

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

// 返回节点数目
template<class T>
int DoubleLink<T>::size()
{
    return count;
}

// 返回链表是否为空
template<class T>
bool DoubleLink<T>::isEmpty()
{
    return count == 0;
}

// 获取第index位置的节点
template<class T>
DNode<T>* DoubleLink<T>::getNode(unsigned int index)
{
    // 判断参数有效性
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

    // 在前半部分，正向查找
    if (index <= count / 2)
    {
        unsigned int i = 0;
        DNode<T>* pindex = phead->next;
        while (i++ < index) {//i == index-1时循环结束
            pindex = pindex->next;
        }

        return pindex;
    }

    // 在后半部分，反向查找
    int j = 0;
    int rindex = count - index - 1;
    DNode<T>* prindex = phead->prev;//尾节点
    while (j++ < rindex) {
        prindex = prindex->prev;
    }

    return prindex;
}

// 获取第index位置的节点的值
template<class T>
T DoubleLink<T>::get(unsigned int index)
{
    return getNode(index)->value;
}

// 获取第1个节点的值
template<class T>
T DoubleLink<T>::getFirst()
{
    return getNode(0)->value;
}

// 获取最后一个节点的值
template<class T>
T DoubleLink<T>::getLast()
{
    return getNode(count - 1)->value;
}

// 将节点插入到第index位置之前
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

template<class T>
int DoubleLink<T>::insertNodeFirst(DNode<T>* pnode) {
    phead->next->prev = pnode;
    phead->next = pnode;
    return 0;
}

// 将节点插入第一个节点处。
template<class T>
int DoubleLink<T>::insertFirst(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
    insertNodeFirst(pnode);
    count++;

    return 0;
}

// 将节点追加到链表的末尾
template<class T>
int DoubleLink<T>::appendLast(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
    phead->prev->next = pnode;
    phead->prev = pnode;
    count++;

    return 0;
}

// 删除节点
template<class T>
int DoubleLink<T>::removeNode(DNode<T>* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    count--;
    return 0;
}

// 删除index位置的节点
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

// 删除index位置的节点
template<class T>
int DoubleLink<T>::del(unsigned int index)
{
    return del(index, NULL);
}

// 删除第一个节点
template<class T>
int DoubleLink<T>::deleteFirst(T* value)
{
    return del(0,value);
}

// 删除第一个节点
template<class T>
int DoubleLink<T>::deleteFirst()
{
    return del(0, NULL);
}

// 删除最后一个节点
template<class T>
int DoubleLink<T>::deleteLast(T* value)
{
    return del(count - 1,value);
}

template<class T>
int DoubleLink<T>::deleteLast()
{
    return del(count - 1, NULL);
}

#endif
