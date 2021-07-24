#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 10);

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "Before *2: " << *it;
        *it = *it * 2;
        cout << ", After *2: " << *it << endl;
    }
}