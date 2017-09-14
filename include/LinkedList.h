#ifndef TEMPLATE_DEMO_HXX
#define TEMPLATE_DEMO_HXX

#include<iostream>

template<class T>
class ListElement
{
public:
    ListElement() { next = NULL; }//初始化
    ListElement(T x) { data = x; next = NULL; }
    T data;//值
    ListElement* next;//指向下一个节点的指针
};

template<class T>
class LinkedList
{
private:
    unsigned int length;
    //ListElement<T>* node;//临时节点
    ListElement<T>* lastnode;//头结点
    ListElement<T>* headnode;//尾节点
    bool firstInit(ListElement<T>* node);
public:
    LinkedList();//初始化
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

template<class T>
LinkedList<T>::LinkedList()
{
    //node = NULL;
    lastnode = NULL;
    headnode = NULL;
    length = 0;
}

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

template<class T>
unsigned int  LinkedList<T>::size() {
    return length;
}

template<class T>
bool LinkedList<T>::firstInit(ListElement<T>* node) {
    bool isFistInit = false;
    if (isEmpty())//如果头结点为空则链表为空,node既为头结点,又是尾节点
    {
        headnode = node;
        lastnode = node;
        isFistInit = true;
    }
    return isFistInit;
}

template<class T>
void  LinkedList<T>::insertTail(T x)//尾插入
{
    ListElement<T>* node = new ListElement<T>();//申请一个新的节点
    node->data = x;//新节点赋值为x
    if (!firstInit(node)) {
        lastnode->next = node;//node既为尾节点的下一个节点
        lastnode = node;//node变成了尾节点,把尾节点赋值为node
    }
    ++length;//元素个数+1
}

template<class T>
void  LinkedList<T>::insert(T x, ListElement<T>* p)
{
    if (p == NULL) return;
    ListElement<T>* node = new ListElement<T>();//申请一个新的空间
    node->data = x;//如图5
    node->next = p->next;
    p->next = node;
    if (node->next == NULL) ｛//如果node为尾节点
        lastnode = node;
    ｝
    ++length;

}
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

template<class T>
void  LinkedList<T>::traversal()
{
    ListElement<T>* node = headnode;//用临时节点指向头结点
    while (node != NULL)//遍历链表并输出
    {
        cout << node->data << ends;
        node = node->next;
    }
    cout << endl;
}

template<class T>
bool  LinkedList<T>::isEmpty()
{
    return headnode == NULL;
}

template<class T>
ListElement<T>* LinkedList<T>::find(T x)
{
    ListElement<T>* node = headnode;//用临时节点指向头结点
    while (node != NULL&&node->data != x)//遍历链表,遇到值相同的节点跳出
    {
        node = node->next;
    }
    return node;//返回找到的节点的地址,如果没有找到则返回NULL
}

template<class T>
void  LinkedList<T>::remove(T x)
{
    ListElement<T>* temp = headnode;//申请一个临时节点指向头节点
    if (temp == NULL) return;//如果头节点为空,则该链表无元素,直接返回
    if (temp->data == x)//如果头节点的值为要删除的值,则删除头节点
    {
        headnode = temp->next;//把头节点指向头节点的下一个节点
        if (temp->next == NULL) lastnode = NULL;//如果链表中只有一个节点,删除之后就没有节点了,把尾节点置为空
        delete(temp);//删除头节点
        return;
    }
    while (temp->next != NULL&&temp->next->data != x)//遍历链表找到第一个值与x相等的节点,temp表示这个节点的上一个节点
    {
        temp = temp->next;
    }//循环结束的条件是temp->next == NULL 或者 temp->next->data == x
    if (temp->next == NULL) {//说明temp是尾节点
        return;//则证明没有找到则返回
    }
    //找到元素了，且该元素为temp->next
    if (temp->next == lastnode)//如果找到的是尾节点
    {
        lastnode = temp;//把尾节点指向他的上一个节点
        delete(temp->next);//删除尾节点
        temp->next = NULL;
    }
    else//如果不是尾节点
    {
        ListElement<T>* node = temp->next;//用临时节点node指向要删除的节点
                                            // 给temp->next重新赋值
        temp->next = node->next;//要删除的节点的上一个节点指向要删除节点的下一个节点
        delete(node);//删除节点
        node = NULL;
    }
    length--;
}

#endif