#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string simple(int a) {
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