const expect = require('chai').expect;
const LRUList = require('../node').LRUList;

const list = new LRUList(3);
const FIRST = 'the first';
const SECOND = 'the second';
const THIRD = 'the third';
const FORTH = 'the forth';
const FIFTH = 'the fifth';
describe('native lru test with string# ',function() {
    it('add FIRST',function(done) {
        list.addOne(FIRST,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(1);
            done();
        });
    });

    it('add SECOND',function(done) {
        list.addOne(SECOND,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(2);
            expect(list.get(0)).to.equal(SECOND);
            expect(list.get(1)).to.equal(FIRST);
            done();
        });
    });

    it('add THIRD',function(done) {
        list.addOne(THIRD,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal(THIRD);
            expect(list.get(1)).to.equal(SECOND);
            expect(list.get(2)).to.equal(FIRST);
            done();
        });
    });

    it('add FORTH',function(done) {
        list.addOne(FORTH,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(true);
            expect(tail).to.equal(FIRST);
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal(FORTH);
            expect(list.get(1)).to.equal(THIRD);
            expect(list.get(2)).to.equal(SECOND);
            done();
        });
    });

    it('add FIFTH',function(done) {
        list.addOne(FIFTH,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(true);
            expect(tail).to.equal(SECOND);
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal(FIFTH);
            expect(list.get(1)).to.equal(FORTH);
            expect(list.get(2)).to.equal(THIRD);
            done();
        });
    });

    it('remove FIFTH',function(done) {
        list.remove(FIFTH,function(count) {
            expect(count).to.equal(1);
            expect(list.size()).to.equal(2);
            expect(list.get(0)).to.equal(FORTH);
            expect(list.get(1)).to.equal(THIRD);
            //console.log(list.get(1));
            done();
        });
    });
});

