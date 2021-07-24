#include <iostream>

using namespace std;

int main(void)
{
    int       i = 0, &r = i;
    auto      a  = r;
    const int ci = i, &cr = ci;
    auto      b = ci;
    auto      c = cr;
    auto      d = &i;
    auto      e = &ci;

    const auto f = ci;
    auto&      g = ci;
    // auto &h = 42;
    const auto& j = 42;
    a             = 42;  // a是个int
    b             = 42;  // b是个int (顶层的const特性被忽略掉)
    c             = 42;  // c是个int
    // d             = 42;  // 非法;d是指向int的指针,不能直接赋值
    // e = 42;  // 非法;e是指向整型常量的指针,不能直接赋值
    // g = 42;  // 非法;g是一个整型常量的引用
}