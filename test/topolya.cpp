// базовые операторы и их приотритеты. разница i++/++i
//(по приоритетам сначала скобки и ++ --, потом арифметические потом сдвиги побитовые потом сравнения потом другие побитовые операции после логические)

#include <iostream>

using namespace std;

#include <iostream>

class Base
{

public:
    void hello() { std::cout << 1 << std::endl; }
};

class Derive : public B
{

public:
    void hello() { std::cout << 2 << std::endl; }
};

void call(Base &b)
{

    b.hello();
}

int main()
{

    Derive b;

    call(b);
}