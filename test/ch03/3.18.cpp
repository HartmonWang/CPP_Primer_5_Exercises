#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    int i;
    while (cin >> i) {
        if (i == 999)
            break;
        v.push_back(i);
    }

    // 1. 输出相邻两个数的和
    cout << "----------------------------------" << endl;

    for (decltype(v.size()) idx = 0; idx != v.size(); idx++) {
        if (idx == 1 || idx / 2)
            cout << "Sum of v[" << idx - 1 << "]:" << v[idx - 1] << " and v["
                 << idx << "]:" << v[idx] << " is " << v[idx - 1] + v[idx]
                 << endl;
    }
    cout << "----------------------------------" << endl;
    // 2. 输出第一个和最后一个元素的和
    for (decltype(v.size()) idx = 0; idx < v.size() / 2; idx++) {
        cout << "Sum of v[" << idx << "]:" << v[idx] << " and v["
             << v.size() - idx << "]:" << v[v.size() - idx] << " is "
             << v[idx] + v[v.size() - idx] << endl;
    }

    cout << "Sum of v[0]:" << v[0] << " and v[" << v.size()
         << "]:" << v[v.size() - 1] << " is " << v[0] + v[v.size() - 1] << endl;
}
