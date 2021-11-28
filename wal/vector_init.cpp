#include <iostream>
#include <vector>

struct Foo {
  int bar_;
  Foo() : bar_(2){};
  Foo(int bar) : bar_(bar){};
};

int main() {
  std::vector<Foo> list(5);
  std::cout << "size: " << list.size() << '\n';
  std::cout << list[0].bar_ << '\n';
  list.reserve(6);
  list.resize(6);
  std::cout << "size: " << list.size() << '\n';
  std::cout << list[5].bar_ << '\n';
  return 0;
}