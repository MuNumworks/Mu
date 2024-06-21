// myclass.cpp
#include "myclass.h"

MyClass::MyClass(int value) : value(value) {}

int MyClass::get_value() const {
    return value;
}

void MyClass::set_value(int value) {
    this->value = value;
}
