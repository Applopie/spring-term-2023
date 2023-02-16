#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a = 10, b = 11, a1 = 10, b1 = 10;
    cin >> a >> b;
    a1 = a, b1 = b;
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    cout << (a1*b1)/a << endl;
    return 0;
}