#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main()
{
    const vector<int> v = {1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

    int sum = accumulate(v.cbegin(), v.cend(), 0);

    cout << "Sum of vector is " << sum << endl;

    return 0;
}