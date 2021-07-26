#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

class Person {
    friend istream& read(istream& is, Person& person);
    friend ostream& print(ostream& os, const Person& persion);

  public:
    Person() = default;
    Person(const string& n, const string& a) : name(n), address(a) {}
    Person(istream& is)
    {
        read(is, *this);
    }

    string get_name() const
    {
        return name;
    };
    string get_address()
    {
        return address;
    };

  private:
    string name;
    string address;
};

istream& read(istream& is, Person& persion)
{
    is >> persion.name >> persion.address;
    return is;
}

ostream& print(ostream& os, const Person& persion)
{
    os << persion.name << persion.address;
    return os;
}

int main()
{
    Person p("dwang", "shanghai");
    string name = p.get_name();
    string addr = p.get_address();

    cout << "Name: " << name << "\nAddress: " << addr << endl;
}