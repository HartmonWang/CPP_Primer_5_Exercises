#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("hello, world");

    for (auto& c : s)
        c = 'X';

    cout << s << endl;
}