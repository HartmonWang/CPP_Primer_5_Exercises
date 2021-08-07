#include <cstring>
#include <iostream>
#include <memory>
#include <string>

int main()
{
    const char s1[] = "Hello, ";
    const char s2[] = "World";

    unsigned len = strlen(s1) + strlen(s2) + 1;
    char*    r   = new char[len];
    std::strcat(r, s1);
    std::strcat(r, s2);
    std::cout << r << std::endl;

    std::string str1 = "HELLO, ";
    std::string str2 = "WORLD !";

    std::strcpy(r, (str1 + str2).c_str());
    std::cout << r << std::endl;
    delete[] r;
}