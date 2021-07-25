#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3) {
        cout << "Usage: ./6.24 <param-1> <param-2>" << endl;
        return -1;
    }

    string test = string(argv[1]) + string(argv[2]);
    cout << "string is: " << test << endl;
}