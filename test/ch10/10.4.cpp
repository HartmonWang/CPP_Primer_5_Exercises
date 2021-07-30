#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;
int main()
{
    vector<int> v(10);

    fill_n(back_inserter(v), 10, 0);

    return 0;
}