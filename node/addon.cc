#include <nan.h>
#include "NodeLRUList.h"

using namespace v8;

void InitAll(Handle<Object> exports, Handle<Object> module) {
    NodeLRUList::Init(exports);
}

NODE_MODULE(lru, InitAll)