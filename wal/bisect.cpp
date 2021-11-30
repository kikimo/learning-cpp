#include <iostream>
#include <vector>

// return index of first elements in elems that's greater than target
// return elems.size() if all elements in elems if smaller than target
int bisectLeft(std::vector<int> &elems, int target) {
  int begin = 0, end = elems.size();

  while (begin < end) {
    int mid = (begin + end) / 2;
    if (elems[mid] >= target) {
      end = mid;
    } else { // elems[mid] <= target
      begin = mid + 1;
    }
  }

  return begin;
}

// return index of first element in elems that's greater of equal to target,
// return elems.size() if all elements in elems is smaller than target
int bisectRight(std::vector<int> &elems, int target) {
  int begin = 0, end = elems.size();

  while (begin < end) {
    int mid = (begin + end) / 2;
    if (elems[mid] > target) {
      end = mid;
    } else {
      begin = mid + 1;
    }
  }

  return begin;
}

int main() {
  std::vector<int> a = {1, 2, 2, 3};
  std::cout << bisectLeft(a, 2) << '\n';
  std::cout << bisectRight(a, 2) << '\n';
  std::cout << bisectRight(a, 4) << '\n';
  std::cout << bisectLeft(a, 4) << '\n';
  std::cout << bisectLeft(a, 1) << '\n';
  std::cout << bisectRight(a, 1) << '\n';

  return 0;
}
