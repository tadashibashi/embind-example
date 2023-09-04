#ifdef EMSCRIPTEN
#include "MyClass.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(myclass) {
    class_<MyClass>("MyClass")
        .constructor<std::string, int>()
        .property("int", &MyClass::getInt, &MyClass::setInt)
        .function("incInt", &MyClass::incInt)
        .class_function("getStringFromInstance", &MyClass::getStringFromInstance)
        ;
}

#endif
