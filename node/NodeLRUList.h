#include <nan.h>
#include "LRUList.h"

class AddOneWorker : public Nan::AsyncWorker {
private:
    LRUList<std::string>* list;
    std::string value;
    std::string removedValue;
    bool tailRemoved;
    uv_mutex_t *lockp;
public:
    AddOneWorker(Nan::Callback *callback,LRUList<std::string>* list,std::string value,uv_mutex_t *lockp)
    : Nan::AsyncWorker(callback), list(list), value(value),lockp(lockp) {
        
    }
    ~AddOneWorker() {}
    void Execute() {
        RemovedTail<std::string> result;

        uv_mutex_lock(lockp);
        list->addNewElement(value,result);
        uv_mutex_unlock(lockp);

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

class RemoveWorker : public Nan::AsyncWorker {
private:
    LRUList<std::string>* list;
    std::string value;
    int deleteCount;
    uv_mutex_t *lockp;
public:
    RemoveWorker(Nan::Callback *callback,LRUList<std::string>* list,std::string value,uv_mutex_t *lockp)
    : Nan::AsyncWorker(callback), list(list), value(value), lockp(lockp) {
        
    }
    ~RemoveWorker() {}
    void Execute() {
        uv_mutex_lock(lockp);
        this->deleteCount = list->deleteByValue(value);
        uv_mutex_unlock(lockp);
    }
    void HandleOKCallback () {
        Nan::HandleScope scope;
        if (callback != NULL) {
            v8::Local<v8::Value> argv[] = {
                Nan::New<v8::Int32>(this->deleteCount)
            };

            callback->Call(1, argv);
        }
            
    }
        
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
    static NAN_METHOD(remove);
    static Nan::Persistent<v8::Function> constructor;
    LRUList<std::string>* list;
    uv_mutex_t lock;
};