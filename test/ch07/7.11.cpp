#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const string& s) : bookNo(s) {}
    Sales_data(const string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n)
    {
    }
    Sales_data(istream&);

    string isbn() const
    {
        return bookNo;
    }
    Sales_data& combine(const Sales_data&);
    double      avg_price() const;
    string      bookNo;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

istream& read(istream& is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
       << item.avg_price();
    return os;
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(istream& is)
{
    read(is, *this);
}

int main(void)
{
    const string s1("ISBN-00001");
    int          n = 10;
    double       p = 68.9;
    Sales_data   sd1;
    Sales_data   sd2(s1);
    Sales_data(s1, n, p);
}