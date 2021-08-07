#include <bits/c++config.h>
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

class StrBlobPtr;
class StrBlob {
  public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il))
    {
    }
    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    // 添加和删除元素
    void push_back(const string& t) { data->push_back(t); }

    void pop_back()
    {
        check(0, "pop_back_on embty StrBlob");
        data->pop_back();
    }

    // 元素访问
    string& front()
    {
        check(0, "pop_back_on embty StrBlob");
        return data->front();
    }
    string& back()
    {
        check(0, "pop_back_on embty StrBlob");
        return data->back();
    }

    StrBlobPtr begin();
    StrBlobPtr end();

  private:
    shared_ptr<vector<string>> data;

    // 如果data[i]不合法, 抛出一个异常
    void check(size_type i, const string& msg) const
    {
        if (i >= data->size()) throw std::out_of_range(msg);
    }
};

// 对于访问一个不存在元素的尝试, StrBlobPtr抛出一个异常
class StrBlobPtr {
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }  // 前缀递增

  private:
    // 若检查成功, check返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<std::string>>
    check(std::size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");

        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    // 保存一个weak_ptr, 意味着底层vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;  // 在数组中的当前位置
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

int main()
{
    StrBlob str1{"hello", "world", "dwang"};
    StrBlob str2{"hello", "world", "hannah"};

    std::cout << str1.front() << " " << str1.back() << std::endl;
    str2.back() = "FAN";
    std::cout << str2.front() << " " << str2.back() << std::endl;

    return 0;
}