const async = require('async');
const expect = require('chai').expect;
const LRUList = require('../node').LRUList;

const LIST_SIZE = 1000;
const TEST_SIZE = 1000000;
const list = new LRUList(LIST_SIZE);

describe('native lru benchmark# ',function(done) {
    it(`test for loop of ${TEST_SIZE}`,function() {
        async.times(TEST_SIZE,function(index,callback) {
            list.addOne(Math.random(),function() {
                callback();
            });
        },function() {
            expect(list.size()).to.be.equal(LIST_SIZE);
            done();
        });
    });
});
