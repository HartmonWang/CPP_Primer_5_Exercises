#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    string address;

  public:
    Person(const string& n, const string& a) : name(n), address(a) {}
    auto get_name() const -> string const&
    {
        return name;
    };
    auto get_address() const -> string const&
    {
        return address;
    };
};

int main()
{
    Person p("dwang", "shanghai");
    string name = p.get_name();
    string addr = p.get_address();

    cout << "Name: " << name << "\nAddress: " << addr << endl;
}