#include <nan.h>
#include "LRUList.h"

class ThreadWorker : public Nan::AsyncWorker {
private:
    LRUList<std::string>* list;
    std::string value;
    std::string removedValue;
    bool tailRemoved;
public:
    ThreadWorker(Nan::Callback *callback,LRUList<std::string>* list,std::string value)
    : Nan::AsyncWorker(callback), list(list), value(value) {
        
    }
    ~ThreadWorker() {}
    void Execute() {
        RemovedTail<std::string> result;
        list->addNewElement(value,result);
        tailRemoved = result.tailRemoved;
        if (tailRemoved) {
            removedValue = result.value;
        }
    }
    void HandleOKCallback () {
        Nan::HandleScope scope;
        if (callback != NULL) {
            if (tailRemoved) {
                v8::Local<v8::Value> argv[] = {
                    Nan::New<v8::Boolean>(tailRemoved),
                    Nan::New<v8::String>(removedValue).ToLocalChecked()
                };
    
                callback->Call(2, argv);
            } else {
                v8::Local<v8::Value> argv[] = {
                    Nan::New<v8::Boolean>(tailRemoved),
                    Nan::Null()
                };
    
                callback->Call(2, argv);
            }
            
        }
        
    };
};

class NodeLRUList : public Nan::ObjectWrap {
public:
    static void Init(v8::Local<v8::Object> exports);
    unsigned int maxLength;
private:
    explicit NodeLRUList(unsigned int maxLength=1024);
    ~NodeLRUList();

    static NAN_METHOD(New);
    static NAN_METHOD(addOne);
    static NAN_METHOD(size);
    static NAN_METHOD(get);
    static Nan::Persistent<v8::Function> constructor;
    LRUList<std::string>* list;
    
};