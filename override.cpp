#include <iostream>

class A {
public:
    void foo();
};

void A::foo() {
    std::cout << "this is B" << std::endl;
}

class B : public A {
public:
    void foo();
};

void B::foo() {
    std::cout << "this is B" << std::endl;
    std::cout << "calling A.foo form B" <<std::endl;
    A::foo();
}

int main()
{
    A a;
    B b;

    a.foo();
    b.foo();

    return 0;
}

