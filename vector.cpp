#include <iostream>
#include <vector>

int search(std::vector<int> &arry, int target) {
    auto begin = arry.begin(), end = arry.end();

    int start = 0;
    while (begin != end) {
        if (*begin == target) {
            return start;
        }

        start++;
        begin++;
    }

    // auto start = arry.begin();
    // auto diff = begin - start;
    // std::cout << "the diff is: " << *diff << std::endl;

    return start;
}

int main()
{
    std::vector<int> arry;
    // std::cout << "arry size:" << arry.size() << std::endl;
    // arry[0] = 1024;
    // arry.push_back(8848);
    // std::cout << "arry size:" << arry.size() << std::endl;
    // std::cout << "last one:" << arry.back() << std::endl;

    for (int i = 0; i < 1024; i++) {
        arry.push_back(i);
    }

    std::cout << "found: " << search(arry, 512) << std::endl;

    return 0;
}
