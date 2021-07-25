#include <iostream>
#include <vector>

using namespace std;

using iter = vector<int>::const_iterator;

void print_vector(const vector<int>& v, int size)
{
    if (--size)
        print_vector(v, size);
    cout << v[size] << endl;
}

int main(void)
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_vector(v, v.size());

    return 0;
}