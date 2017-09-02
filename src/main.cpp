#include <iostream>
#include "LinkedList.h"

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
	return 0;
}
