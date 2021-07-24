#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;

    string i;
    while (cin >> i) {
        if (i == "quit")
            break;
        v.push_back(i);
    }
    for (auto& i : v) {
        for (decltype(i.size()) idx = 0; idx != i.size() && isalpha(i[idx]);
             ++idx) {
            i[idx] = toupper(i[idx]);
        }
    }
    for (auto i : v) {
        cout << i << endl;
    }
}