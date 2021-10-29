#include <iostream>
#include <vector>
#include <thread>

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; i++) {
        threads.emplace_back([]() {
            long total = 0;
            for (long i = 0; i < 10000000000; i++) {
                total += i;
            }

            std::cout << "total: " << total << std::endl;
        });
    }

    for (int i = 0; i < 4; i++) {
        threads[i].join();
    }

    std::cout << "over!" << std::endl;

    return 0;
}

