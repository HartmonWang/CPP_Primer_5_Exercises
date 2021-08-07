#include <iostream>
#include <set>
#include <string>
#include <vector>

class Message {
    friend class Folder;

  public:
    explicit Message(const std::string& str = "") : contents(str) {}
};

class Folder {
  private:
    std::string str;
};