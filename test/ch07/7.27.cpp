#include <iostream>
#include <string>

using namespace std;
class Screen {
  public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
    }
    Screen&       move(pos r, pos c);
    Screen&       set(char c);
    Screen&       set(pos r, pos c, char ch);
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
    char get() const
    {
        return contents[cursor];
    }
    char get(pos r, pos c) const
    {
        return contents[r * width + c];
    }

  private:
    void do_display(ostream& os) const
    {
        os << contents;
    }
    pos    cursor = 0;
    pos    height = 0, width = 0;
    string contents;
};

Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
    cursor           = r * width + c;
    contents[cursor] = ch;
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