#include <iostream>

using namespace std;

void swap_point(int*& a, int*& b)
{
    auto tmp = a;
    a        = b;
    b        = tmp;
}

int main(void)
{
    int  a = 10, b = 20;
    int *pa = &a, *pb = &b;
    swap_point(pa, pb);

    cout << " a: " << *pa << " b: " << *pb << endl;
}