#include <iostream>
#include <cmath>

using namespace std;

int recursive_power(int base, int power) {
    if (power == 0 or base == 1) {
        return 1;
    }
    else {
        return recursive_power(base, power - 1)*base;
        }
    }

int main() {
    int a = 1, b = 5;
    cin >> a >> b;
    cout << recursive_power(a, b) << endl;
    return 0;
}