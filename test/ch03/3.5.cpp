#include <iostream>
#include <string>

using namespace std;

int main()
{
    string result, s;
    while (cin >> s) {
        if (s == "quit")
            break;
        result += s + " ";
    }
    cout << result << endl;
}