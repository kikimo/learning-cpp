#include <iostream>
#include <exception>

class MyExcept : public std::runtime_error {
public:
  MyExcept(std::string what_arg): std::runtime_error(what_arg) {}
};

int main()
{
    try
    {
        throw std::runtime_error("hello world");
    }
    catch(const MyExcept& e)
    {
        throw std::runtime_error("should not happend here");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << typeid(e).name() << '\n';
    }

    try
    {
        throw MyExcept("this is my exception!");
    }
    catch(const MyExcept& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << typeid(e).name() << '\n';
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("should not happend here");
    }

    throw MyExcept("hello exception!");
    
    return 0;
}
