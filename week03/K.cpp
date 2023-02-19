#include <iostream>
#include <cmath>
#include <algorithm>

#ifndef N
#define N 3
#endif

using namespace std;

int main() {
    int a[N*N], b = 0;
    for (int i = 0; i < N*N; i++) {
        cin >> a[i];
    }
    b = b + a[0];
    for (int i = 1; i < N*N; i++) {
        if (i%(N + 1) == 0) {
            b = b + a[i];
        }
    }
    cout << b << endl;
    return 0;
}