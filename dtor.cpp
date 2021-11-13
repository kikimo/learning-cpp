#include <iostream>

using namespace std;

class Base {
  public:
    ~Base() { cout << "base class destroyed" << '\n'; }
};

class Foo : public Base {
  public:
    ~Foo() { cout << "Foo class destroyed" << '\n';}
};

int main()
{
	Foo f;
	return 0;
}

