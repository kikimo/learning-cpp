#include <iostream>
#include <stdio.h>
#include <string>

int main() {
  char buf[256];
  int size = std::snprintf(buf, sizeof(buf), "%016d", 1);
  printf("size: %d\n", size);
  printf("%09d\n", 1);
  std::string name(buf, size);
  std::cout << "file name: " << name << '\n';

  return 0;
}
