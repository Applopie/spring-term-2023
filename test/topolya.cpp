// базовые операторы и их приотритеты. разница i++/++i
#include <iostream>

using namespace std;

void cube(int *a) // a или &a
{
    int t = *a * *a;
    *a = t;
}

int main()
{
    int i = 0;
    int a = ++i;
    cout << a << ' ' << i << endl;
    i = 0;
    int b = i++;
    cout << b << ' ' << i << endl;

    int x = 5;
    int *x1 = &x;
    cube(x1);
    cout << x << endl;

    // указатели. адреса переменных
    int t = 9;
    int *p = &t;
    int *p1 = p;
    cout << p << ' ' << *p << ' ' << p1 << ' ' << *p1 << endl;
    return 0;
}
