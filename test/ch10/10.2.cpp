#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main()
{
    const list<string> lst = {"hi", "hi", "hi", "wo"};

    const string value1 = "hi";

    int num_value1 = count(lst.cbegin(), lst.cend(), value1);

    cout << "Count of " << value1 << " is: " << num_value1 << endl;

    return 0;
}