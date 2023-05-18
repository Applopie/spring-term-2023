// базовые операторы и их приотритеты. разница i++/++i
//(по приоритетам сначала скобки и ++ --, потом арифметические потом сдвиги побитовые потом сравнения потом другие побитовые операции после логические)

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
    double t = 9;
    double *p = &t;
    double *p1 = p;
    p1 = p1 + 2;
    cout << sizeof(p1 - p) << endl;
    return 0;
}
