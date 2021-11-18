#include <iostream>
#include <memory>

std::weak_ptr<int> wptr;

void observe()
{
    auto sptr = wptr.lock();
    if (sptr != nullptr)
    {
        std::cout << "the value is:" << *sptr << '\n';
    }
    else
    {
        std::cout << "the weak ptr has expired" << '\n';
    }
}

int main()
{
    {
        auto sptr = std::make_shared<int>(8848);
        wptr = sptr;
        observe();
    }

    observe();

    return 0;
}
