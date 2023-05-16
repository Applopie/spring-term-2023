#include <iostream>

using namespace std;

void swap1(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void swap2(int **a, int **b)
{
    int *p = *a;
    *a = *b;
    *b = p;
}

int main()
{
    int a = 6, b = 9;
    int *a1 = &a, *b1 = &b;
    int **a2 = &a1, **b2 = &b1;
    swap2(a2, b2);
    cout << a << ' ' << b << endl;
    return 0;
}