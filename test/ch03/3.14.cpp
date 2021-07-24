#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    int i;
    while (cin >> i) {
        if (i == 99)
            break;
        v.push_back(i);
    }
    for (auto i : v)
        cout << i << endl;
}