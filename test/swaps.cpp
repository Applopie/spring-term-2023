#include <iostream>

using namespace std;

void swap1(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void swap2(int *a, int *b)
{
    int *p = new int;
    *p = *a;
    *a = *b;
    *b = *p;
    delete p;
}

int main()
{
    int a = 6, b = 9;
    int *a1 = &a, *b1 = &b;
    swap2(a1, b1);
    cout << *a1 << ' ' << *b1 << endl;

    int x = 1, y = 2;
    swap(x, y);
    cout << x << ' ' << y << endl;
    return 0;
}