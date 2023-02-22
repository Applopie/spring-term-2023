#include <iostream>
#include <cmath>

using namespace std;

string_view_literals twotwo(int c) {
    while (c % 2 == 0) {
        c = c/2;
    }
    if (c == 1) {
        return "YES";
    }
    else {
        return "NO";
    }
}

int main() {
    int a = 9;
    cin >> a;
    cout << twotwo(a) << endl;
    return 0;
}
