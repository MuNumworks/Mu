// myclass.h
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    MyClass(int value);
    int get_value() const;
    void set_value(int value);

private:
    int value;
};

#endif // MYCLASS_H
