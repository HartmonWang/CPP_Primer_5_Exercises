#include <iostream>
#include <memory>
#include <string>

struct destination
{
    std::string ip;
    int         port;
    destination(std::string i, int p) : ip(i), port(p) {}
};

struct connection
{
    std::string ip;
    int         port;
    connection(std::string i, int p) : ip(i), port(p){};
};

connection connect(destination* dst)
{
    std::shared_ptr<connection> conn(new connection(dst->ip, dst->port));
    std::cout << "create connection(" << conn.use_count() << ")" << std::endl;
    return *conn;
}

void disconnect(connection conn)
{
    std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
              << std::endl;
}

void f(destination& d)
{
    connection                  c = connect(&d);
    std::shared_ptr<connection> p(&c,
                                  [](connection* conn) { disconnect(*conn); });
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main(void)
{
    destination dst("114.114.114.114", 53);
    f(dst);

    return 0;
}