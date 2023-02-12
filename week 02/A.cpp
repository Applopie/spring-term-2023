#include <iostream>

using namespace std;

int main() {
    int a = 10;
    cin >> a;
    if (a % 400 == 0 and a != 0) {
        cout << "YES" << endl;
    }
    else if (a % 100 == 0 or a == 0) {
        cout << "NO" << endl; 
    }
    else if (a%4 == 0) {
        cout << "YES" << endl; 
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
