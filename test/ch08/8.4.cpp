#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void read_to_vector(const string f, vector<string>& v)
{
    string   buf;
    ifstream istrm(f, ios::in);
    if (!istrm.is_open()) {
        cout << "Failed to open " << f << '\n';
    }
    else {
        while (getline(istrm, buf))
            v.push_back(buf);
    }
}
int main(void)
{
    vector<string> v;
    const string   f("./test.txt");
    read_to_vector(f, v);

    for (auto elem : v)
        cout << elem;
    cout << endl;

    return 0;
}