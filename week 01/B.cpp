#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 1, b = 2, c = 1;
    cin >> a >> b >> c;
    if (b*b - 4*a*c > 0) {
        cout << ((-b + sqrt(b*b - 4*a*c))/(2*a)) << " "<< ((-b - sqrt(b*b - 4*a*c))/(2*a)) << endl;
    }
    else if (b*b - 4*a*c == 0) {
        cout << ((-b + sqrt(b*b - 4*a*c))/(2*a)) << endl;
    }
    else {cout << '\n' << endl; }
    return 0;
}