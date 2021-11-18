#include <iostream>
#include <thread>

int main()
{
    std::thread t([]() {
        std::cout << "thread running" << '\n';
    });

    std::cout << t.joinable();
    t.join();
    std::cout << t.joinable();
    t.join();
    return 0;
}