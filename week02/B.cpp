#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 3, k = 0;
    while (a != 0) {
        cin >> a;
        if (abs(a) % 2 == 0) {
            k = k++;
        }
    }
    cout << k << endl;
    return 0;
}