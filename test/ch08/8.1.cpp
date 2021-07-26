#include <iostream>

using namespace std;

istream& read_data(istream& is)
{
    string buf;
    while (is >> buf)
        cout << buf << endl;
    is.clear();
    return is;
}

int main(void)
{
    read_data(cin);
}