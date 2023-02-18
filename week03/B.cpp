#include <iostream>
#include <cmath>

using namespace std;

#ifndef N
#define N 3
#endif

int main() {
    int k = 0, a[N];
    cin >> k;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}