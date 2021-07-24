#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string s("hello, world");
    string       result;

    for (auto& c : s)
        if (!ispunct(c))
            result += c;
    cout << result << endl;
}