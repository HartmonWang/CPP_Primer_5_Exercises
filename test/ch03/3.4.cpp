#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;

    if (s1 < s2)
        cout << "S2 is bigger" << endl;
    else if (s1 == s2)
        cout << "S1 == S2" << endl;
    else
        cout << "S1 is bigger" << endl;

    if (s1.size() > s2.size())
        cout << "S1 is longer" << endl;
    else if (s1.size() < s2.size())
        cout << "S2 is longer" << endl;
    else
        cout << "S1.size() == S2.size()";
}