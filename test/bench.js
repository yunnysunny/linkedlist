const async = require('async');
const expect = require('chai').expect;
const LRUList = require('../node').LRUList;

const LIST_SIZE = 8192;
const TEST_SIZE = 102400;
var list = new LRUList(LIST_SIZE);

describe('native lru benchmark# ',function() {
    it(`test for loop of ${TEST_SIZE}`,function(done) {
        async.times(TEST_SIZE,function(index,callback) {
            const begin=Date.now();
            list.addOne(Math.random()+'',function() {
                const used = Date.now()-begin;
                if (used>1000) {
                    //console.warn('used much time',used,index);
                }
                callback();
            });
        },function() {
            expect(list.size()).to.be.equal(LIST_SIZE);
            // list = null;
            done();
        });
    });
    it('test after bench',function(done) {
        const begin=Date.now();
        list.addOne(Math.random()+'',function() {
            const used = Date.now()-begin;
            if (used>1000) {
                //console.warn('used much time',used,index);
            }
            done();
        });
    });
});
