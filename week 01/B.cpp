#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 1, b = 2, c = 1;
    cin >> a >> b >> c;
    if (a != 0) {
        if (b*b - 4*a*c > 0) {
        float x1 = ((-b - sqrt(b*b - 4*a*c))/(2*a)), x2 = ((-b + sqrt(b*b - 4*a*c))/(2*a));
        if (x1 > x2) {
            cout << x2 << " "<< x1 << endl;
        }
        else {
            cout << x1 << " " << x2 << endl;
        }
    }
    else if (b*b - 4*a*c == 0) {
        cout << ((-b + sqrt(b*b - 4*a*c))/(2*a)) << endl;
    }
    else {cout << '\n' << endl; }
    }
    else {
        cout << -c/b << endl;
    }
    return 0;
}
