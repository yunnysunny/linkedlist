/**
 * This file is only used for creating document.
 * @module native-linked-list
 */

/**
 * @function AddElementToLRUListCallback
 * 
 * @param {Boolean} isTailRemoved
 * @param {String} removedTailValue
 */

/**
 * @function RemoveElementCallback
 * @param {Number} removedCount
 */


/**
 * The class of NodeLRUList
 * 
 * @class NodeLRUList
 */
class NodeLRUList {
    constructor(count) {
        this.count = count;
    }
    /**
     * return the size of current list
     * 
     * @returns {Number} The size of current list
     * @memberof NodeLRUList    
     * 
     */
    size() {
        return this.count;
    }
    /**
     * Add element to lru list, when its size is equal `count`, the tail will be removed.
     * 
     * @param {String} The element you want to add.
     * @param {AddElementToLRUListCallback} callback 
     * @memberof NodeLRUList
     */
    addOne(key,callback) {

    }
    /**
     * Remove an element by key.
     * 
     * @param {String} key 
     * @param {RemoveElementCallback} callback 
     * @memberof NodeLRUList
     */
    remove(key,callback) {}

    /**
     * Get a value by key.
     * 
     * @param {String} key 
     * @return {String} value
     * @memberof NodeLRUList
     */
    get(key) {

    }
}

module.exports = NodeLRUList;