#include <iostream>

using namespace std;

int copmare_two_int(int a, int* b)
{
    return a > *b ? a : *b;
}

int main(void)
{
    int a = 10, b = 20;
    int ret = 0;

    ret = copmare_two_int(a, &b);

    cout << " a: " << a << " b: " << b << endl;
    cout << "The bigger: " << ret << endl;
}