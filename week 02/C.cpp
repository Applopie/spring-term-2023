#include <iostream>
#include <cmath>

using namespace std;

bool twotwo(int c) {
    while (c % 2 == 0) {
        c = c/2;
    }
    if (c == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int a = 9;
    cin >> a;
    cout << twotwo(a) << endl;
    return 0;
}
