#include <iostream>
#include <thread>
#include <memory>
#include <folly/futures/Promise.h>

int main()
{
    printf("hello world!\n");

    // folly future/promise example
    auto promise = std::make_shared<folly::Promise<int>>();
    auto fut = promise->getFuture();
    std::thread t([](folly::Future<int> f){
        int val = std::move(f).get();
        std::cout << "val:" << val << std::endl;
    }, std::move(fut));

    promise->setValue(848);
    t.join();

    return 0;
}
