#include <iostream>
#include "LinkedList.h"
#include "DoubleLink.h"
#include "LRUList.h"

using namespace std;

int main(int argc, char **argv)
{
    LinkedList<int>* list = new LinkedList<int>();
    list->insertTail(1);
    list->insertTail(2);
    list->insertTail(3);
    list->remove(2);
    list->insertHead(9);
    list->traversal();
    ListElement<int>* e = list->find(5);
    if (e != NULL) {
        cout << "check none exist find failed" << endl;
        return 1;
    }
    cout << "check none exist find success" << endl;

    e = list->find(3);
    if (e == NULL || e->data != 3) {
        cout << "check exist find failed" << endl;
        return 2;
    }
    cout << "check exist find success" << endl;

    DoubleLink<int>* dlink = new DoubleLink<int>();
    dlink->insert_first(1);
    dlink->append_last(2);
    dlink->append_last(3);
    dlink->append_last(4);
    DNode<int>* node = dlink->find_node(3);
    if (node == NULL) {
        cout << "double link find error" << endl;
        return 3;
    }
    dlink->delete_last();
    dlink->delete_first();
    dlink->traversal();

    LRUList<int>* lru = new LRUList<int>(3);
    RemovedTail<int> result;
    lru->addNewElement(1,result);
    cout << "remove tail " << result.tailRemoved << endl;
    lru->addNewElement(2, result);
    cout << "remove tail " << result.tailRemoved << endl;
    lru->addNewElement(3, result);
    cout << "remove tail " << result.tailRemoved << endl;
    lru->addNewElement(4, result);
    cout << "remove tail " << result.tailRemoved << " " << result.value << endl;
    lru->addNewElement(5, result);
    cout << "remove tail " << result.tailRemoved << " " << result.value << endl;
    lru->traversal();
	return 0;
}
