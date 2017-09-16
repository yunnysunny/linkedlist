/**
 * This file is only used for creating document.
 */

/**
 * @function AddElementToLRUListCallback
 * 
 * @param {Boolean} isTailRemoved
 * @param {String} removedTailValue
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
     * @param {String} key 
     * @param {AddElementToLRUListCallback} callback 
     * @memberof NodeLRUList
     */
    addOne(key,callback) {

    }
}

module.exports = NodeLRUList;