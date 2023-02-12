#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 4, k = 0;
    while (a != 0) {
        cin >> a;
        if (abs(a) % 2 == 0) {
            k = k + 1;
        }
    }
    cout << k << endl;
    return 0;
}
