#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string simple(int a) {
    if ((int) sqrt(a) == sqrt(a) or a == 1 or a == 0) {
        return "NO";
    }
    for (int i = 2; i < sqrt(a); i++) {
        if (a % i == 0) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int num = 5;
    cin >> num;
    cout << simple(num) << endl;
    return 0;
}
