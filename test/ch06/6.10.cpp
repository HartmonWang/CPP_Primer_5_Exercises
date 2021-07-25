#include <iostream>

using namespace std;

void swap_int(int* a, int* b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
}

int main(void)
{
    int a = 1, b = 2;
    cout << "Before swap, a: " << a << " b: " << b << endl;

    swap_int(&a, &b);
    cout << "After swap, a: " << a << " b: " << b << endl;
    return 0;
}