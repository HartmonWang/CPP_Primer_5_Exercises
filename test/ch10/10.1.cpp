#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    const vector<int> v = {1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

    const int value1 = 3;

    int num_value1 = count(v.cbegin(), v.cend(), value1);

    cout << "Count of " << value1 << " is: " << num_value1 << endl;

    return 0;
}