#include <nan.h>
#include "NodeLRUList.h"

using namespace v8;

NAN_MODULE_INIT(InitAll) {
    NodeLRUList::Init(target);
}

NODE_MODULE(lru, InitAll)