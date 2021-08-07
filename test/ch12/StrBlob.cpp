#include <initializer_list>
#include <iostream>
#include <memory>  // shared_ptr
#include <stdexcept>
#include <string>
#include <vector>
using std::initializer_list;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob {
  public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il))
    {
    }
    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    // 添加和删除元素
    void push_back(const string& t) { data->push_back(t); }

    void pop_back();

    // 元素访问
    string& front();
    string& back();

  private:
    shared_ptr<vector<string>> data;

    // 如果data[i]不合法, 抛出一个异常
    void check(size_type i, const string& msg) const
    {
        if (i >= data->size()) throw std::out_of_range(msg);
    }
};
string& StrBlob::front()
{
    check(0, "pop_back_on embty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "pop_back_on embty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back_on embty StrBlob");
    data->pop_back();
}

int main()
{
    StrBlob str1{"hello", "world", "dwang"};
    StrBlob str2{"hello", "world", "hannah"};

    std::cout << str1.front() << " " << str1.back() << std::endl;
    str2.back() = "FAN";
    std::cout << str2.front() << " " << str2.back() << std::endl;

    return 0;
}