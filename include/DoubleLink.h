#ifndef DOUBLE_LINK_HXX
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
    bool is_empty();

    T get(unsigned int index);
    T get_first();
    T get_last();
    DNode<T>* find_node(T t);
    void traversal();//����������������ӡ

    int insert(unsigned int index, T t);
    int insert_first(T t);
    int append_last(T t);

    int del(unsigned int index,T* value=NULL);
    int delete_first(T* value = NULL);
    int delete_last(T* value = NULL);

protected:
    unsigned int count;
    DNode<T> *phead;
    int remove_node(DNode<T>* node);
    int insert_node_first(DNode<T>* node);
private:
    DNode<T> *get_node(unsigned int index);
};

template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
    // ��������ͷ����ע�⣺��ͷû�д洢���ݣ�
    phead = new DNode<T>();
    phead->prev = phead->next = phead;
    // ������������Ϊ0
    //count = 0;
}

// ��������
template<class T>
DoubleLink<T>::~DoubleLink()
{
    // ɾ�����еĽڵ�
    DNode<T>* ptmp;
    DNode<T>* pnode = phead->next;
    while (pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode->next;
        delete ptmp;
    }

    // ɾ��"��ͷ"
    delete phead;
    phead = NULL;
}

template<class T>
DNode<T>* DoubleLink<T>::find_node(T t) {
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

// ���ؽڵ���Ŀ
template<class T>
int DoubleLink<T>::size()
{
    return count;
}

// ���������Ƿ�Ϊ��
template<class T>
bool DoubleLink<T>::is_empty()
{
    return count == 0;
}

// ��ȡ��indexλ�õĽڵ�
template<class T>
DNode<T>* DoubleLink<T>::get_node(unsigned int index)
{
    // �жϲ�����Ч��
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

    // ��ǰ�벿�֣��������
    if (index <= count / 2)
    {
        unsigned int i = 0;
        DNode<T>* pindex = phead->next;
        while (i++ < index) {//i == index-1ʱѭ������
            pindex = pindex->next;
        }

        return pindex;
    }

    // �ں�벿�֣��������
    int j = 0;
    int rindex = count - index - 1;
    DNode<T>* prindex = phead->prev;//β�ڵ�
    while (j++ < rindex) {
        prindex = prindex->prev;
    }

    return prindex;
}

// ��ȡ��indexλ�õĽڵ��ֵ
template<class T>
T DoubleLink<T>::get(unsigned int index)
{
    return get_node(index)->value;
}

// ��ȡ��1���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_first()
{
    return get_node(0)->value;
}

// ��ȡ���һ���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_last()
{
    return get_node(count - 1)->value;
}

// ���ڵ���뵽��indexλ��֮ǰ
template<class T>
int DoubleLink<T>::insert(unsigned int index, T t)
{
    if (index == 0)
        return insert_first(t);

    DNode<T>* pindex = get_node(index);
    DNode<T>* pnode = new DNode<T>(t, pindex->prev, pindex);
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;

    return 0;
}

template<class T>
int DoubleLink<T>::insert_node_first(DNode<T>* pnode) {
    phead->next->prev = pnode;
    phead->next = pnode;
    return 0;
}

// ���ڵ�����һ���ڵ㴦��
template<class T>
int DoubleLink<T>::insert_first(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
    insert_node_first(pnode);
    count++;

    return 0;
}

// ���ڵ�׷�ӵ�������ĩβ
template<class T>
int DoubleLink<T>::append_last(T t)
{
    DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
    phead->prev->next = pnode;
    phead->prev = pnode;
    count++;

    return 0;
}

// ɾ���ڵ�
template<class T>
int DoubleLink<T>::remove_node(DNode<T>* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    count--;
    return 0;
}

// ɾ��indexλ�õĽڵ�
template<class T>
int DoubleLink<T>::del(unsigned int index,T* value=NULL)
{
    if (index<0 || index >= count)
    {
        cout << "get node failed! the index in out of bound!" << endl;
        return 1;
    }
    DNode<T>* pindex = get_node(index);
    if (value != NULL) {
        *value = pindex->value;
    }
    remove_node(pindex);
    delete pindex;
    return 0;
}

// ɾ����һ���ڵ�
template<class T>
int DoubleLink<T>::delete_first(T* value = NULL)
{
    return del(0,value);
}

// ɾ�����һ���ڵ�
template<class T>
int DoubleLink<T>::delete_last(T* value = NULL)
{
    return del(count - 1,value);
}

#endif