#include "NodeLRUList.h"

Nan::Persistent<v8::Function> NodeLRUList::constructor;

NodeLRUList::NodeLRUList(unsigned int maxLength): maxLength(maxLength) {
    list = new LRUList<std::string>(maxLength);
}

NodeLRUList::~NodeLRUList() {
    delete list;
}

void NodeLRUList::Init(v8::Local<v8::Object> exports) {
    // Prepare constructor template
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);//
    tpl->SetClassName(Nan::New<v8::String>("LRUList").ToLocalChecked());//js中的类名为NodeLRUList
    tpl->InstanceTemplate()->SetInternalFieldCount(1);//

    Nan::SetPrototypeMethod(tpl,"addOne",addOne);//
    Nan::SetPrototypeMethod(tpl,"size",size);//
    
    constructor.Reset(tpl->GetFunction());
    exports->Set(Nan::New<v8::String>("LRUList").ToLocalChecked(), tpl->GetFunction());
}

NAN_METHOD(NodeLRUList::New) {
    if (info.IsConstructCall()) {
        // 通过 `new LRUList(...)` 方式调用
        unsigned int value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
        NodeLRUList* obj = new NodeLRUList(value);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        // 通过 `LRUList(...)` 方式调用, 转成使用构造函数方式调用
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = { info[0] };
        v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
        info.GetReturnValue().Set(cons->NewInstance(argc, argv));
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
    
    Nan::AsyncQueueWorker(new ThreadWorker(callback,obj->list,stdstr));

    info.GetReturnValue().Set(Nan::Undefined());
}