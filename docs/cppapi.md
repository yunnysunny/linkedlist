# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`DoubleLink`](#class_double_link) | The class of [DoubleLink](#class_double_link)
`class `[`LinkedList`](#class_linked_list) | 
`class `[`ListElement`](#class_list_element) | 
`class `[`LRUList`](#class_l_r_u_list) | The class of [LRUList](#class_l_r_u_list)
`class `[`RemovedTail`](#class_removed_tail) | A class used for mark whether the tail node is removed when insert a new element to the LRU list.
`struct `[`DNode`](#struct_d_node) | The class of [DNode](#struct_d_node), used it for [DoubleLink](#class_double_link)

# class `DoubleLink` {#class_double_link}

The class of [DoubleLink](#class_double_link)
 ``` |-|>|-| |tail| |head| |-|<|-| ```

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DoubleLink`](#class_double_link_1a2234fe49e8fff52feef3fa6e463a932c)`()` | The constructor
`public  `[`~DoubleLink`](#class_double_link_1ae1e5c415db44b0136f2c92975e84d13e)`()` | 
`public int `[`size`](#class_double_link_1a594532d1a5cc9c27caf5e0fbe0fa161f)`()` | Get the count of nodes
`public bool `[`isEmpty`](#class_double_link_1a9865201a43307a054e00a8e3db2305b6)`()` | Check if the list is empty.
`public T `[`get`](#class_double_link_1aba5044e7325fca2a8625a0c7e9298353)`(unsigned int index)` | Get the value of the `index` node
`public T `[`getFirst`](#class_double_link_1ae2e723f4674718254a813c33976a3665)`()` | Get first node's value
`public T `[`getLast`](#class_double_link_1a77dea8890ada9309bcb8d3e4529a1867)`()` | Get the last node's value
`public `[`DNode`](#struct_d_node)`< T > * `[`findNode`](#class_double_link_1a69bb1ac5376d95fe5396cd97f10568e2)`(T t)` | Find a node by a T element
`public void `[`traversal`](#class_double_link_1a15e2eb74a5f774eb879a18e215ecbbf5)`()` | traverse all the nodes
`public int `[`insert`](#class_double_link_1a80c0896451672a5c3495d7720e31516f)`(unsigned int index,T t)` | Insert the element to the front of index's node.
`public int `[`insertFirst`](#class_double_link_1addb39017e36bbb386b597ccd61cd9246)`(T t)` | Create a node and insert it to the first
`public int `[`appendLast`](#class_double_link_1a179bac987e6bff7f245a505c4c15bed6)`(T t)` | Create a node and insert it to the tail
`public int `[`del`](#class_double_link_1ae8bca2979c0d1bddbae07d04e9f1b256)`(unsigned int index,T * value)` | Remove the index's node, and copy the value to the porint of `value`.
`public int `[`del`](#class_double_link_1a6d76e246d212ff54fde85d2ad58f9375)`(unsigned int index)` | Remove the index's node.
`public int `[`deleteFirst`](#class_double_link_1af0da20a96b6431ec3aea4caa5abac5e7)`(T * value)` | Remove the first node, and save its value to `value`.
`public int `[`deleteFirst`](#class_double_link_1a5cf74f907cd90da588439475de01fc95)`()` | Remove the first node.
`public int `[`deleteLast`](#class_double_link_1a38c85c38ffd5eba1215aa3ceb5c1f79c)`(T * value)` | Remove the last node, and save its value to `value`.
`public int `[`deleteLast`](#class_double_link_1a58949efa715002912923eed6b849f840)`()` | Remove the last node.
`protected unsigned int `[`count`](#class_double_link_1acec4e088ed0936e79897003790b22d97) | 
`protected `[`DNode`](#struct_d_node)`< T > * `[`phead`](#class_double_link_1a98225ccd319db4b9a1a4a5037a9c8eb8) | 
`protected int `[`removeNode`](#class_double_link_1a671263252b05361adde7fd5fbd3a3490)`(`[`DNode`](#struct_d_node)`< T > * node)` | Remove an exist node
`protected int `[`insertNodeFirst`](#class_double_link_1ac8c15c5c8537d8eef035cb926ff4b30e)`(`[`DNode`](#struct_d_node)`< T > * node)` | Insert the node to the first.

## Members

#### `public  `[`DoubleLink`](#class_double_link_1a2234fe49e8fff52feef3fa6e463a932c)`()` {#class_double_link_1a2234fe49e8fff52feef3fa6e463a932c}

The constructor

#### `public  `[`~DoubleLink`](#class_double_link_1ae1e5c415db44b0136f2c92975e84d13e)`()` {#class_double_link_1ae1e5c415db44b0136f2c92975e84d13e}

#### `public int `[`size`](#class_double_link_1a594532d1a5cc9c27caf5e0fbe0fa161f)`()` {#class_double_link_1a594532d1a5cc9c27caf5e0fbe0fa161f}

Get the count of nodes

#### `public bool `[`isEmpty`](#class_double_link_1a9865201a43307a054e00a8e3db2305b6)`()` {#class_double_link_1a9865201a43307a054e00a8e3db2305b6}

Check if the list is empty.

#### `public T `[`get`](#class_double_link_1aba5044e7325fca2a8625a0c7e9298353)`(unsigned int index)` {#class_double_link_1aba5044e7325fca2a8625a0c7e9298353}

Get the value of the `index` node

#### `public T `[`getFirst`](#class_double_link_1ae2e723f4674718254a813c33976a3665)`()` {#class_double_link_1ae2e723f4674718254a813c33976a3665}

Get first node's value

#### `public T `[`getLast`](#class_double_link_1a77dea8890ada9309bcb8d3e4529a1867)`()` {#class_double_link_1a77dea8890ada9309bcb8d3e4529a1867}

Get the last node's value

#### `public `[`DNode`](#struct_d_node)`< T > * `[`findNode`](#class_double_link_1a69bb1ac5376d95fe5396cd97f10568e2)`(T t)` {#class_double_link_1a69bb1ac5376d95fe5396cd97f10568e2}

Find a node by a T element

#### `public void `[`traversal`](#class_double_link_1a15e2eb74a5f774eb879a18e215ecbbf5)`()` {#class_double_link_1a15e2eb74a5f774eb879a18e215ecbbf5}

traverse all the nodes

#### `public int `[`insert`](#class_double_link_1a80c0896451672a5c3495d7720e31516f)`(unsigned int index,T t)` {#class_double_link_1a80c0896451672a5c3495d7720e31516f}

Insert the element to the front of index's node.

#### `public int `[`insertFirst`](#class_double_link_1addb39017e36bbb386b597ccd61cd9246)`(T t)` {#class_double_link_1addb39017e36bbb386b597ccd61cd9246}

Create a node and insert it to the first

#### `public int `[`appendLast`](#class_double_link_1a179bac987e6bff7f245a505c4c15bed6)`(T t)` {#class_double_link_1a179bac987e6bff7f245a505c4c15bed6}

Create a node and insert it to the tail

#### `public int `[`del`](#class_double_link_1ae8bca2979c0d1bddbae07d04e9f1b256)`(unsigned int index,T * value)` {#class_double_link_1ae8bca2979c0d1bddbae07d04e9f1b256}

Remove the index's node, and copy the value to the porint of `value`.

#### `public int `[`del`](#class_double_link_1a6d76e246d212ff54fde85d2ad58f9375)`(unsigned int index)` {#class_double_link_1a6d76e246d212ff54fde85d2ad58f9375}

Remove the index's node.

#### `public int `[`deleteFirst`](#class_double_link_1af0da20a96b6431ec3aea4caa5abac5e7)`(T * value)` {#class_double_link_1af0da20a96b6431ec3aea4caa5abac5e7}

Remove the first node, and save its value to `value`.

#### `public int `[`deleteFirst`](#class_double_link_1a5cf74f907cd90da588439475de01fc95)`()` {#class_double_link_1a5cf74f907cd90da588439475de01fc95}

Remove the first node.

#### `public int `[`deleteLast`](#class_double_link_1a38c85c38ffd5eba1215aa3ceb5c1f79c)`(T * value)` {#class_double_link_1a38c85c38ffd5eba1215aa3ceb5c1f79c}

Remove the last node, and save its value to `value`.

#### `public int `[`deleteLast`](#class_double_link_1a58949efa715002912923eed6b849f840)`()` {#class_double_link_1a58949efa715002912923eed6b849f840}

Remove the last node.

#### `protected unsigned int `[`count`](#class_double_link_1acec4e088ed0936e79897003790b22d97) {#class_double_link_1acec4e088ed0936e79897003790b22d97}

#### `protected `[`DNode`](#struct_d_node)`< T > * `[`phead`](#class_double_link_1a98225ccd319db4b9a1a4a5037a9c8eb8) {#class_double_link_1a98225ccd319db4b9a1a4a5037a9c8eb8}

#### `protected int `[`removeNode`](#class_double_link_1a671263252b05361adde7fd5fbd3a3490)`(`[`DNode`](#struct_d_node)`< T > * node)` {#class_double_link_1a671263252b05361adde7fd5fbd3a3490}

Remove an exist node

#### `protected int `[`insertNodeFirst`](#class_double_link_1ac8c15c5c8537d8eef035cb926ff4b30e)`(`[`DNode`](#struct_d_node)`< T > * node)` {#class_double_link_1ac8c15c5c8537d8eef035cb926ff4b30e}

Insert the node to the first.

# class `LinkedList` {#class_linked_list}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`LinkedList`](#class_linked_list_1a3c20fcfec867e867f541061a09fc640c)`()` | The constructor
`public  `[`~LinkedList`](#class_linked_list_1a7c37609df3b83bc4eb0281b852f93fd7)`()` | The destructor
`public unsigned int `[`size`](#class_linked_list_1ae9fea698cdc45cc02efc2f7fbc85d29f)`()` | Get the size of current list.
`public void `[`insertTail`](#class_linked_list_1a975689cc865a8caba7385388b7c96bde)`(T x)` | Create a new node and insert it to tail.
`public void `[`traversal`](#class_linked_list_1acc5231550842b8a2e7f02ab7128bf5f7)`()` | Traverse and print the nodes
`public bool `[`isEmpty`](#class_linked_list_1a7ecbb28e82117a680839ed0dc28ebdce)`()` | Check whether the list is empty.
`public `[`ListElement`](#class_list_element)`< T > * `[`find`](#class_linked_list_1ac79d55007453b306e37f195669ea7f9c)`(T x)` | Find the first one which its data is `x`.
`public void `[`remove`](#class_linked_list_1ae29e7c0a91f8a86a5e37df56f4364434)`(T x)` | Remove the first one which its data is `x`.
`public void `[`insert`](#class_linked_list_1a3255bcb866fbca4c4b3551797303c096)`(T x,`[`ListElement`](#class_list_element)`< T > * p)` | Create a node and insert it to the next of `p`.
`public void `[`insertHead`](#class_linked_list_1a8ae79a705a21298eac486106d4207c98)`(T x)` | Create a new node and insert it to the head

## Members

#### `public  `[`LinkedList`](#class_linked_list_1a3c20fcfec867e867f541061a09fc640c)`()` {#class_linked_list_1a3c20fcfec867e867f541061a09fc640c}

The constructor

#### `public  `[`~LinkedList`](#class_linked_list_1a7c37609df3b83bc4eb0281b852f93fd7)`()` {#class_linked_list_1a7c37609df3b83bc4eb0281b852f93fd7}

The destructor

#### `public unsigned int `[`size`](#class_linked_list_1ae9fea698cdc45cc02efc2f7fbc85d29f)`()` {#class_linked_list_1ae9fea698cdc45cc02efc2f7fbc85d29f}

Get the size of current list.

#### `public void `[`insertTail`](#class_linked_list_1a975689cc865a8caba7385388b7c96bde)`(T x)` {#class_linked_list_1a975689cc865a8caba7385388b7c96bde}

Create a new node and insert it to tail.

#### `public void `[`traversal`](#class_linked_list_1acc5231550842b8a2e7f02ab7128bf5f7)`()` {#class_linked_list_1acc5231550842b8a2e7f02ab7128bf5f7}

Traverse and print the nodes

#### `public bool `[`isEmpty`](#class_linked_list_1a7ecbb28e82117a680839ed0dc28ebdce)`()` {#class_linked_list_1a7ecbb28e82117a680839ed0dc28ebdce}

Check whether the list is empty.

#### `public `[`ListElement`](#class_list_element)`< T > * `[`find`](#class_linked_list_1ac79d55007453b306e37f195669ea7f9c)`(T x)` {#class_linked_list_1ac79d55007453b306e37f195669ea7f9c}

Find the first one which its data is `x`.

#### `public void `[`remove`](#class_linked_list_1ae29e7c0a91f8a86a5e37df56f4364434)`(T x)` {#class_linked_list_1ae29e7c0a91f8a86a5e37df56f4364434}

Remove the first one which its data is `x`.

#### `public void `[`insert`](#class_linked_list_1a3255bcb866fbca4c4b3551797303c096)`(T x,`[`ListElement`](#class_list_element)`< T > * p)` {#class_linked_list_1a3255bcb866fbca4c4b3551797303c096}

Create a node and insert it to the next of `p`.

#### `public void `[`insertHead`](#class_linked_list_1a8ae79a705a21298eac486106d4207c98)`(T x)` {#class_linked_list_1a8ae79a705a21298eac486106d4207c98}

Create a new node and insert it to the head

# class `ListElement` {#class_list_element}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public T `[`data`](#class_list_element_1a3e0fef099e819e54b9aa609f1a9453d0) | 
`public `[`ListElement`](#class_list_element)` * `[`next`](#class_list_element_1ad3adfca0f9d599149459ad4718d192ee) | 
`public inline  `[`ListElement`](#class_list_element_1afbb967d196c925f04dc916d3efee4b88)`()` | 
`public inline  `[`ListElement`](#class_list_element_1a5b8a9aaba74364b628ec533010d754cb)`(T x)` | 

## Members

#### `public T `[`data`](#class_list_element_1a3e0fef099e819e54b9aa609f1a9453d0) {#class_list_element_1a3e0fef099e819e54b9aa609f1a9453d0}

#### `public `[`ListElement`](#class_list_element)` * `[`next`](#class_list_element_1ad3adfca0f9d599149459ad4718d192ee) {#class_list_element_1ad3adfca0f9d599149459ad4718d192ee}

#### `public inline  `[`ListElement`](#class_list_element_1afbb967d196c925f04dc916d3efee4b88)`()` {#class_list_element_1afbb967d196c925f04dc916d3efee4b88}

#### `public inline  `[`ListElement`](#class_list_element_1a5b8a9aaba74364b628ec533010d754cb)`(T x)` {#class_list_element_1a5b8a9aaba74364b628ec533010d754cb}

# class `LRUList` {#class_l_r_u_list}

```
class LRUList
  : public DoubleLink< T >
```  

The class of [LRUList](#class_l_r_u_list)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`LRUList`](#class_l_r_u_list_1a67714cc7fe54de11231d91a2f9e86e59)`(unsigned int count)` | The constructor of [LRUList](#class_l_r_u_list), it will init a double list , with a max lenght of `count`.
`public void `[`addNewElement`](#class_l_r_u_list_1ae0ce4e791e1c8c2e9d854dc2c2d7f95c)`(T e,`[`RemovedTail`](#class_removed_tail)`< T > & remvedTail)` | Add a new element to the lru list's head, if current length is equal `maxCount`, the tail node will be removed.

## Members

#### `public  `[`LRUList`](#class_l_r_u_list_1a67714cc7fe54de11231d91a2f9e86e59)`(unsigned int count)` {#class_l_r_u_list_1a67714cc7fe54de11231d91a2f9e86e59}

The constructor of [LRUList](#class_l_r_u_list), it will init a double list , with a max lenght of `count`.

#### `public void `[`addNewElement`](#class_l_r_u_list_1ae0ce4e791e1c8c2e9d854dc2c2d7f95c)`(T e,`[`RemovedTail`](#class_removed_tail)`< T > & remvedTail)` {#class_l_r_u_list_1ae0ce4e791e1c8c2e9d854dc2c2d7f95c}

Add a new element to the lru list's head, if current length is equal `maxCount`, the tail node will be removed.

# class `RemovedTail` {#class_removed_tail}

A class used for mark whether the tail node is removed when insert a new element to the LRU list.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public T `[`value`](#class_removed_tail_1acd4fa6064a4fde345286cc44dcc6ae2c) | 
`public bool `[`tailRemoved`](#class_removed_tail_1a60b002f245b2341c2e967ca235ab4e88) | 
`public inline  `[`RemovedTail`](#class_removed_tail_1a627496e97174e575f36a0c26c0134f94)`()` | The constructor of [RemovedTail](#class_removed_tail)

## Members

#### `public T `[`value`](#class_removed_tail_1acd4fa6064a4fde345286cc44dcc6ae2c) {#class_removed_tail_1acd4fa6064a4fde345286cc44dcc6ae2c}

#### `public bool `[`tailRemoved`](#class_removed_tail_1a60b002f245b2341c2e967ca235ab4e88) {#class_removed_tail_1a60b002f245b2341c2e967ca235ab4e88}

#### `public inline  `[`RemovedTail`](#class_removed_tail_1a627496e97174e575f36a0c26c0134f94)`()` {#class_removed_tail_1a627496e97174e575f36a0c26c0134f94}

The constructor of [RemovedTail](#class_removed_tail)

# struct `DNode` {#struct_d_node}

The class of [DNode](#struct_d_node), used it for [DoubleLink](#class_double_link)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public T `[`value`](#struct_d_node_1a557604208e1ad4e6540a4098a5d08b47) | 
`public `[`DNode`](#struct_d_node)` * `[`prev`](#struct_d_node_1a60baec7505ba9191707eadf34e383ee8) | 
`public `[`DNode`](#struct_d_node)` * `[`next`](#struct_d_node_1a241190a5a779e031b3ae9c6019690428) | 
`public inline  `[`DNode`](#struct_d_node_1a16b187e0b38fb59d55b09046f9c61357)`()` | 
`public inline  `[`DNode`](#struct_d_node_1ae693af6f92a3b83b373d3e2807631f7c)`(T t,`[`DNode`](#struct_d_node)` * prev,`[`DNode`](#struct_d_node)` * next)` | 

## Members

#### `public T `[`value`](#struct_d_node_1a557604208e1ad4e6540a4098a5d08b47) {#struct_d_node_1a557604208e1ad4e6540a4098a5d08b47}

#### `public `[`DNode`](#struct_d_node)` * `[`prev`](#struct_d_node_1a60baec7505ba9191707eadf34e383ee8) {#struct_d_node_1a60baec7505ba9191707eadf34e383ee8}

#### `public `[`DNode`](#struct_d_node)` * `[`next`](#struct_d_node_1a241190a5a779e031b3ae9c6019690428) {#struct_d_node_1a241190a5a779e031b3ae9c6019690428}

#### `public inline  `[`DNode`](#struct_d_node_1a16b187e0b38fb59d55b09046f9c61357)`()` {#struct_d_node_1a16b187e0b38fb59d55b09046f9c61357}

#### `public inline  `[`DNode`](#struct_d_node_1ae693af6f92a3b83b373d3e2807631f7c)`(T t,`[`DNode`](#struct_d_node)` * prev,`[`DNode`](#struct_d_node)` * next)` {#struct_d_node_1ae693af6f92a3b83b373d3e2807631f7c}

Generated by [Moxygen](https://sourcey.com/moxygen)