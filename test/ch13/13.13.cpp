#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

void test(const X& rx, X x)
{
    std::vector<X> v;
    v.reserve(10);
    std::cout << __LINE__ << std::endl;

    v.push_back(rx);
    std::cout << __LINE__ << std::endl;

    v.push_back(x);
}
int main(void)
{
    std::cout << __LINE__ << std::endl;
    X* px = new X;
    std::cout << __LINE__ << std::endl;

    X x = X();
    std::cout << __LINE__ << std::endl;

    test(*px, x);
    std::cout << __LINE__ << std::endl;

    delete px;
    std::cout << __LINE__ << std::endl;

    return 0;
}