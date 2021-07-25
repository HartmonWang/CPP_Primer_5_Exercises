#include <iostream>
#include <iterator>

using namespace std;

void print(const char* cp)
{
    if (cp)
        while (*cp)
            cout << *cp++ << endl;
    cout << endl;
}

void print(const int i)
{
    cout << i << endl;
}

void print(const int* pi)
{
    if (pi)
        cout << *pi << endl;
}

void print(const int* beg, const int* end)
{
    while (beg != end)
        cout << *beg++ << endl;
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}

void print(int (&arr)[2])
{
    for (auto elem : arr)
        cout << elem << endl;
}

int main(void)
{
    int        i = 0, j[2] = {0, 1};
    const char str[] = "hello, world";

    print(i);
    print(j);
    print(str);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j) - begin(j));

    return 0;
}