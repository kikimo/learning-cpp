#include <iostream>
#include <list>

int main() {
  std::list<int> elems;
  auto first = elems.insert(elems.end(), 1);
  auto second = elems.insert(elems.end(), 2);
  auto third = elems.insert(elems.end(), 3);
  std::cout << "expect three elements:" << std::endl;
  for (auto it = elems.begin(); it != elems.end(); ++it) {
    std::cout << (*it) << std::endl;
  }

  elems.erase(second);
  elems.erase(third);

  std::cout << "expect one:" << std::endl;
  for (auto it = elems.begin(); it != elems.end(); ++it) {
    std::cout << (*it) << std::endl;
  }

  return 0;
}
