#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string pldr(string a) {
    if (a.length() == 1) {
        return "YES";
    }
    else if(a.length()%2 == 0) {
        for (int i = 0; i < a.length()/2; i++) {
            if (a[i] != a[a.length() - i - 1]) {
                return "NO";
            }
        }
        return "YES";
    }
    else {
        for (int i = 0; i < (a.length() - 1)/2; i++) {
            if (a[i] != a[a.length() - i - 1]) {
                return "NO";
            }
        }
        return "YES";
    }
}

int main() {
    string a = "valkyrie";
    cin >> a;
    cout << pldr(a) << endl; 
    return 0;
}