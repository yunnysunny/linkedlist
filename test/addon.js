const expect = require('chai').expect;
const LRUList = require('../node').LRUList;

const list = new LRUList(3);
describe('native lru test# ',function() {
    it('add 1',function(done) {
        list.addOne(1,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(1);
            done();
        });
    });

    it('add 2',function(done) {
        list.addOne(2,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(2);
            expect(list.get(0)).to.equal('2');
            expect(list.get(1)).to.equal('1');
            done();
        });
    });

    it('add 3',function(done) {
        list.addOne(3,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(false);
            expect(tail).to.equal(null);
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal('3');
            expect(list.get(1)).to.equal('2');
            expect(list.get(2)).to.equal('1');
            done();
        });
    });

    it('add 4',function(done) {
        list.addOne(4,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(true);
            expect(tail).to.equal('1');
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal('4');
            expect(list.get(1)).to.equal('3');
            expect(list.get(2)).to.equal('2');
            done();
        });
    });

    it('add 5',function(done) {
        list.addOne(5,function(tailRemoved,tail) {
            expect(tailRemoved).to.equal(true);
            expect(tail).to.equal('2');
            expect(list.size()).to.equal(3);
            expect(list.get(0)).to.equal('5');
            expect(list.get(1)).to.equal('4');
            expect(list.get(2)).to.equal('3');
            done();
        });
    });
});

