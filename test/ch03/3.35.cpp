#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int arr[10];

    for (int* p = arr; p != end(arr); ++p)
        *p = 0;

    for (int* p = arr; p != end(arr); ++p)
        cout << *p << endl;
}