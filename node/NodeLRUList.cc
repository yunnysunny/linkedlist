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
    
    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(exports, Nan::New<v8::String>("LRUList").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(NodeLRUList::New) {
    if (info.IsConstructCall()) {
        // call by `new LRUList(...)` 
        unsigned int value = info[0]->IsUndefined() ? 0 : Nan::To<uint32_t>(info[0]).FromJust();
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
    v8::Local<v8::String> v8_string = Nan::ToDetailString(info[0]).ToLocalChecked();
    Nan::Utf8String nan_string(v8_string);
    std::string cc_string(*nan_string);
    
    Nan::AsyncQueueWorker(new AddOneWorker(callback,obj->list,cc_string, &(obj->lock)));

    info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(NodeLRUList::get) {
    NodeLRUList* obj = ObjectWrap::Unwrap<NodeLRUList>(info.Holder());
    unsigned int value = info[0]->IsUndefined() ? 0 :  Nan::To<uint32_t>(info[0]).FromJust();

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
    v8::Local<v8::String> v8_string = Nan::ToDetailString(info[0]).ToLocalChecked();
    Nan::Utf8String nan_string(v8_string);
    std::string cc_string(*nan_string);
    // Nan::Utf8String *param1 = new Nan::Utf8String( info[0]);
    // std::string stdstr = std::string(param1);
    // delete param1;
    
    Nan::AsyncQueueWorker(new RemoveWorker(callback,obj->list,cc_string, &(obj->lock)));

    info.GetReturnValue().Set(Nan::Undefined());
}