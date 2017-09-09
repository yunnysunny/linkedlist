#include <nan.h>
#include "NativeLRUList.h"

using namespace v8;

void InitAll(Handle<Object> exports, Handle<Object> module) {
    NativeLRUList::Init(module);
}

NODE_MODULE(lru, InitAll)