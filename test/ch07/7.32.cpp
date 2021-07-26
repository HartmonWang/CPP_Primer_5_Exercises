#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
  public:
    using ScreenIndx = vector<Screen>::size_type;
    inline void clear(ScreenIndx);

  private:
    vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndx);

  public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
    }

    char get() const
    {
        return contents[cursor];
    }
    char get(pos r, pos c) const
    {
        return contents[r * width + c];
    }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(ostream& os) const
    {
        do_display(os);
        return *this;
    }
    Screen& display(ostream& os)
    {
        do_display(os);
        return *this;
    }

  private:
    void do_display(ostream& os) const
    {
        os << contents;
    }
    pos    cursor = 0;
    pos    width = 0, height = 0;
    string contents;
};

inline void Window_mgr::clear(ScreenIndx i)
{
    Screen& s  = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    cursor           = r * width + c;
    contents[cursor] = c;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}