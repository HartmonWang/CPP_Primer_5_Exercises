#include <bits/c++config.h>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);

  public:
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1))
    {
    }
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i), use(p.use)
    {
        ++*use;
    }
    HasPtr& operator=(const HasPtr& p);

    ~HasPtr();

  private:
    std::string* ps;
    int          i;
    std::size_t* use;
};

inline void swap(HasPtr& p1, HasPtr& p2)
{
    using std::swap;
    swap(p1.ps, p2.ps);
    swap(p1.i, p2.i);
}

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& p)
{
    ++*p.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps  = p.ps;
    i   = p.i;
    use = p.use;

    return *this;
}
int main(void) { return 0; }