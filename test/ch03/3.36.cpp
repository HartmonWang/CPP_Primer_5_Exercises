#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

bool arrary_compare(int* pb1, int* pe1, int* pb2, int* pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2))
        return false;
    auto      sz = pb1 - pe1;
    ptrdiff_t idx;
    for (idx = 0; idx < sz; ++idx) {
        cout << "idx: " << idx << pb1[idx] << endl;
        if (pb1[idx] != pb2[idx])
            return false;
    }
    return true;
}

int main()
{
    int         a1[3] = {1, 2, 3};
    int         b1[3] = {1, 2, 3};
    vector<int> a2{1, 2, 3, 4};
    vector<int> b2{1, 2, 3, 5};
    bool        result;

    cout << "--------------------------" << endl;
    cout << "Array a1 is: ";
    for (auto i : a1)
        cout << i << " ";
    cout << endl;

    cout << "Array b1 is: ";
    for (auto i : b1)
        cout << i << " ";
    cout << endl;

    result = arrary_compare(begin(a1), end(a1), begin(b1), end(b1));
    if (result)
        cout << "The two array is equal" << endl;
    else
        cout << "The two array is not equal" << endl;

    cout << "--------------------------" << endl;
    cout << "Vector a2 is: ";
    for (auto i : a2)
        cout << i << " ";
    cout << endl;

    cout << "Vector b2 is: ";
    for (auto i : b2)
        cout << i << " ";
    cout << endl;

    if (a2 == b2)
        cout << "The two vector is equal" << endl;
    else
        cout << "The two vector is not equal" << endl;

    return 0;
}