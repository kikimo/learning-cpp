#include <fstream>
#include <iostream>

int main() {
  auto openMode = std::fstream::in | std::fstream::out | std::fstream::binary |
                  std::fstream::app;
  std::fstream f("./test.bin", openMode);
  if (!f.good()) {
    std::cout << "fuck\n";
  }

  return 0;
}