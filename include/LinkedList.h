#ifndef TEMPLATE_DEMO_HXX
#define TEMPLATE_DEMO_HXX

#include<iostream>

template<class T>
class ListElement
{
public:
    ListElement() { next = NULL; }//
    ListElement(T x) { data = x; next = NULL; }
    T data;//
    ListElement* next;//the pointer point to next element
};

template<class T>
class LinkedList
{
private:
    unsigned int length;
    ListElement<T>* lastnode;//last node
    ListElement<T>* headnode;//head node
    bool firstInit(ListElement<T>* node);
public:
    LinkedList();//
    ~LinkedList();
    unsigned int size();//链表元素的个数
    void insertTail(T x);//表尾添加元素
    void traversal();//遍历整个链表并打印
    bool isEmpty();//判断链表是否为空
    ListElement<T>* find(T x);//查找第一个值为x的节点,返回节点的地址,找不到返回NULL
    void remove(T x);//删除第一个值为x的节点
    void insert(T x, ListElement<T>* p);//在p节点后插入值为x的节点
    void insertHead(T x);//在链表的头部插入节点
};

/////////////////////////////////////////
/**
* The constructor
*/
template<class T>
LinkedList<T>::LinkedList()
{
    //node = NULL;
    lastnode = NULL;
    headnode = NULL;
    length = 0;
}
/**
* The destructor
*/
template<class T>
LinkedList<T>::~LinkedList()
{
    ListElement<T>* node = headnode;//
    while (node != NULL)//遍历链表
    {        
        ListElement<T>* temp = node;
        node = node->next;
        delete(temp);
        
    }
    lastnode = NULL;
    headnode = NULL;
    length = 0;
}
/**
* Get the size of current list.
*/
template<class T>
unsigned int  LinkedList<T>::size() {
    return length;
}

/**
* Check whether current list is empty, when empty init it. 
*/
template<class T>
bool LinkedList<T>::firstInit(ListElement<T>* node) {
    bool isFistInit = false;
    if (isEmpty())//When empty, both the head node and last node will point to `node`
    {
        headnode = node;
        lastnode = node;
        isFistInit = true;
    }
    return isFistInit;
}

/**
* Create a new node and insert it to tail.
*/
template<class T>
void  LinkedList<T>::insertTail(T x)//
{
    ListElement<T>* node = new ListElement<T>();//
    node->data = x;//
    if (!firstInit(node)) {
        lastnode->next = node;//append to last
        lastnode = node;//node is now the last
    }
    ++length;//
}

/**
 * Create a node and insert it to the next of `p`.
 */
template<class T>
void  LinkedList<T>::insert(T x, ListElement<T>* p)
{
    if (p == NULL) return;
    ListElement<T>* node = new ListElement<T>();//申请一个新的空间
    node->data = x;//
    node->next = p->next;
    p->next = node;
    if (node->next == NULL) ｛//This is none node after `node`
        lastnode = node;
    ｝
    ++length;

}

/**
 * Create a new node and insert it to the head
 */
template<class T>
void  LinkedList<T>::insertHead(T x)
{
    ListElement<T>* node = new ListElement<T>();
    node->data = x;
    if (!firstInit(node)) {
        node->next = headnode;
        headnode = node;
    }
    ++length;
}

/**
 * Traverse and print the nodes
 */
template<class T>
void  LinkedList<T>::traversal()
{
    ListElement<T>* node = headnode;//
    while (node != NULL)//
    {
        cout << node->data << ends;
        node = node->next;
    }
    cout << endl;
}

/**
 * Check whether the list is empty.
 */
template<class T>
bool  LinkedList<T>::isEmpty()
{
    return headnode == NULL;
}
/**
 * Find the first one which its data is `x`.
 */
template<class T>
ListElement<T>* LinkedList<T>::find(T x)
{
    ListElement<T>* node = headnode;//
    while (node != NULL&&node->data != x)//
    {
        node = node->next;
    }
    return node;//return a point of node ,or NULL if none find
}

/**
 * Remove the first one which its data is `x`.
 */
template<class T>
void  LinkedList<T>::remove(T x)
{
    ListElement<T>* temp = headnode;//the temp node point to head
    if (temp == NULL) return;//return if list is empty
    if (temp->data == x)//if the head's data is x, delete the head node
    {
        headnode = temp->next;//move the head to the next
        if (temp->next == NULL) lastnode = NULL;//if the next is empty, the last node will also be null
        delete(temp);//delete head
        return;
    }
    while (temp->next != NULL/*the next is not empty*/&&temp->next->data != x/*the next's data is not x*/)
    {
        temp = temp->next;
    }//when temp->next == NULL or temp->next->data == x ,the loop end
    if (temp->next == NULL) {//The temp is the last now
        return;//none found
    }
    //find one ,it is temp->next
    if (temp->next == lastnode)//The one we found is the tail
    {
        lastnode = temp;//move last node to temp
        delete(temp->next);//delete the find one
        temp->next = NULL;
    }
    else//The one we found is not the tail
    {
        ListElement<T>* node = temp->next;//a pointer points to the found one
                                            //
        temp->next = node->next;//temp's next now point the found one's next
        delete(node);//delete the found one
        node = NULL;
    }
    length--;
}

#endif