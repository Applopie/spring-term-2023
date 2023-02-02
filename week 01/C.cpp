#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a = 0, b = 1;
    cin >> a;
    if (a == 0) {
        cout << '1' << endl;
    }
    else {
        for (int i = 1; i < a + 1; i++) {
            b *= i;
        }
        cout << b << endl;
    }
    return 0;
}