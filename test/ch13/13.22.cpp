#include <iostream>
#include <string>
#include <vector>

class HasPtr {
  public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr& operator=(const HasPtr& p)
    {
        auto new_p = new std::string(*p.ps);
        delete ps;
        ps = new_p;
        i  = p.i;
        return *this;
    }

    ~HasPtr() { delete ps; }

  private:
    std::string* ps;
    int          i;
};

int main(void) { return 0; }