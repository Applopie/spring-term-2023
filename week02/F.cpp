#include <iostream>
#include <cmath>

using namespace std;

int recursive_fact(int a) {
    if (a == 0) {
        return 1;
    }
    else if (a == 1) {
        return 1;
    }
    else {
        return recursive_fact(a - 1)*a;
    }
}

int main() {
    int a = 9;
    cin >> a;
    cout << recursive_fact(a) << endl;
    return 0;
}