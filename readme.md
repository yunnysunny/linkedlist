# linked list

[![NPM version](https://img.shields.io/npm/v/native-linked-list.svg?style=flat-square)](https://npmjs.com/package/native-linked-list)
[![Build status](https://travis-ci.org/yunnysunny/linkedlist.svg?branch=master)](https://travis-ci.org/yunnysunny/linkedlist)

A library supports `single linked list` `double linked list` and `lru list`.

## How to use

```c++
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
    dlink->insertFirst(1);
    dlink->appendLast(2);
    dlink->appendLast(3);
    dlink->appendLast(4);
    DNode<int>* node = dlink->findNode(3);
    if (node == NULL) {
        cout << "double link find error" << endl;
        return 3;
    }
    dlink->deleteLast();
    dlink->deleteFirst();
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
```

## API

See the [api](doc/cppapi.md) document.

## Node addon

A node wrapper is supplied, only supports lru list now. See its [api](doc/jsapi.md).

### Install npm package

```
npm install native-linked-list --save
```

### Demo

```javascript
const {LRUList} = require('native-linked-list');
const {expect} = require('chai');
const list = new LRUList(3);
list.addOne(1,function(tailRemoved,tail) {
    expect(tailRemoved).to.equal(false);
    expect(tail).to.equal(null);
    expect(list.size()).to.equal(1);
});
list.addOne(2,function(tailRemoved,tail) {
    expect(tailRemoved).to.equal(false);
    expect(tail).to.equal(null);
    expect(list.size()).to.equal(2);
    expect(list.get(0)).to.equal('2');
    expect(list.get(1)).to.equal('1');
});
list.addOne(3,function(tailRemoved,tail) {
    expect(tailRemoved).to.equal(false);
    expect(tail).to.equal(null);
    expect(list.size()).to.equal(3);
    expect(list.get(0)).to.equal('3');
    expect(list.get(1)).to.equal('2');
    expect(list.get(2)).to.equal('1');
});
list.addOne(4,function(tailRemoved,tail) {
    expect(tailRemoved).to.equal(true);
    expect(tail).to.equal('1');
    expect(list.size()).to.equal(3);
    expect(list.get(0)).to.equal('4');
    expect(list.get(1)).to.equal('3');
    expect(list.get(2)).to.equal('2');
});
```

## License

[MIT](LICENSE)