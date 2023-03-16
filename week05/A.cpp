#include <iostream>

using namespace std;

int main() {
    double a = 0;
    double *ptr = &a;
    cout << &a << ' ' << ptr << endl;
    ptr = ptr - 3;
    cout << ptr << ' ' << *ptr << endl;
    ptr = ptr + 5;
    cout << ptr << ' ' << *ptr << endl;
    return 0;
}