#include "NodeLRUList.h"

Nan::Persistent<v8::Function> NodeLRUList::constructor;

NodeLRUList::NodeLRUList(unsigned int maxLength): maxLength(maxLength) {
    list = new LRUList<std::string>(maxLength);
    uv_mutex_init(&lock);
}

NodeLRUList::~NodeLRUList() {
    delete list;
    uv_mutex_destroy(&lock);
}

void NodeLRUList::Init(v8::Local<v8::Object> exports) {
    // Prepare constructor template
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);//
    tpl->SetClassName(Nan::New<v8::String>("LRUList").ToLocalChecked());//js' class name is LRUList
    tpl->InstanceTemplate()->SetInternalFieldCount(1);//

    Nan::SetPrototypeMethod(tpl,"addOne",addOne);//
    Nan::SetPrototypeMethod(tpl,"size",size);//
    Nan::SetPrototypeMethod(tpl,"get",get);
    Nan::SetPrototypeMethod(tpl,"remove",remove);
    
    constructor.Reset(tpl->GetFunction());
    Nan::Set(exports, Nan::New<v8::String>("LRUList").ToLocalChecked(), tpl->GetFunction());
}

NAN_METHOD(NodeLRUList::New) {
    if (info.IsConstructCall()) {
        // call by `new LRUList(...)` 
        unsigned int value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
        NodeLRUList* obj = new NodeLRUList(value);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        // call by  `LRUList(...)`, change to constructor mode
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = { info[0] };
        v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
        info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
    }
}

NAN_METHOD(NodeLRUList::size) {
    NodeLRUList* obj = ObjectWrap::Unwrap<NodeLRUList>(info.Holder());
    info.GetReturnValue().Set(Nan::New(obj->list->size()));
}

NAN_METHOD(NodeLRUList::addOne) {
    NodeLRUList* obj = ObjectWrap::Unwrap<NodeLRUList>(info.Holder());
    if (info[0]->IsUndefined()) {
        Nan::ThrowError("The value can not be empty");
        return info.GetReturnValue().Set(Nan::Undefined());
    }

    if (info[0]->IsNumber()) {
    } else if (info[0]->IsString()) {
    } else {
        Nan::ThrowError("The value must be a string or number");
        return info.GetReturnValue().Set(Nan::Undefined());
    }
    Nan::Callback *callback = NULL;
    if (!info[1]->IsUndefined()) {
        callback = new Nan::Callback(info[1].As<v8::Function>());
    }
    Nan::Utf8String param1(info[0]->ToString());
    std::string stdstr = std::string(*param1);
    
    Nan::AsyncQueueWorker(new AddOneWorker(callback,obj->list,stdstr, &(obj->lock)));

    info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(NodeLRUList::get) {
    NodeLRUList* obj = ObjectWrap::Unwrap<NodeLRUList>(info.Holder());
    unsigned int value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();

    std::string str = obj->list->get(value);

    info.GetReturnValue().Set(Nan::New<v8::String>(str).ToLocalChecked());
}

NAN_METHOD(NodeLRUList::remove) {
    NodeLRUList* obj = ObjectWrap::Unwrap<NodeLRUList>(info.Holder());
    if (info[0]->IsUndefined()) {
        Nan::ThrowError("The value can not be empty");
        return info.GetReturnValue().Set(Nan::Undefined());
    }
    if (info[0]->IsNumber()) {
    } else if (info[0]->IsString()) {
    } else {
        Nan::ThrowError("The value must be a string or number");
        return info.GetReturnValue().Set(Nan::Undefined());
    }

    Nan::Callback *callback = NULL;
    if (!info[1]->IsUndefined()) {
        callback = new Nan::Callback(info[1].As<v8::Function>());
    }
    Nan::Utf8String param1(info[0]->ToString());
    std::string stdstr = std::string(*param1);
    
    Nan::AsyncQueueWorker(new RemoveWorker(callback,obj->list,stdstr, &(obj->lock)));

    info.GetReturnValue().Set(Nan::Undefined());
}