#include <iostream>
#include <cmath>

using namespace std;

int fibonacchi(int i) {
    if (i == 0 or i == 1) {
        return 1;
    }
    else {
        return fibonacchi(i - 1) + fibonacchi(i - 2);
    }
}

int main() {
    int a = 0;
    cin >> a;
    cout << fibonacchi(a) << endl;
    return 0;
}