## Classes

<dl>
<dt><a href="#NodeLRUList">NodeLRUList</a></dt>
<dd></dd>
</dl>

## Functions

<dl>
<dt><a href="#AddElementToLRUListCallback">AddElementToLRUListCallback(isTailRemoved, removedTailValue)</a></dt>
<dd></dd>
</dl>

<a name="NodeLRUList"></a>

## NodeLRUList
**Kind**: global class  

* [NodeLRUList](#NodeLRUList)
    * [new NodeLRUList()](#new_NodeLRUList_new)
    * [.size()](#NodeLRUList+size) ⇒ <code>Number</code>
    * [.addOne(key, callback)](#NodeLRUList+addOne)

<a name="new_NodeLRUList_new"></a>

### new NodeLRUList()
The class of NodeLRUList

<a name="NodeLRUList+size"></a>

### nodeLRUList.size() ⇒ <code>Number</code>
return the size of current list

**Kind**: instance method of [<code>NodeLRUList</code>](#NodeLRUList)  
**Returns**: <code>Number</code> - The size of current list  
<a name="NodeLRUList+addOne"></a>

### nodeLRUList.addOne(key, callback)
Add element to lru list, when its size is equal `count`, the tail will be removed.

**Kind**: instance method of [<code>NodeLRUList</code>](#NodeLRUList)  

| Param | Type |
| --- | --- |
| key | <code>String</code> | 
| callback | [<code>AddElementToLRUListCallback</code>](#AddElementToLRUListCallback) | 

<a name="AddElementToLRUListCallback"></a>

## AddElementToLRUListCallback(isTailRemoved, removedTailValue)
**Kind**: global function  

| Param | Type |
| --- | --- |
| isTailRemoved | <code>Boolean</code> | 
| removedTailValue | <code>String</code> | 

