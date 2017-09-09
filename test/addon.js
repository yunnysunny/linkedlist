const LRUList = require('../build/Release/native-linked-list');

const list = new LRUList(3);

list.addOne(1);
list.addOne(2);
list.addOne(3);
list.addOne(4);
list.addOne(5);

console.log(list.size());
