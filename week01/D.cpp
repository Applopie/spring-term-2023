#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a = 10, b = 11;
    cin >> a >> b;
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    cout << a << endl;
    return 0;
}