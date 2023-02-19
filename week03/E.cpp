#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#ifndef N
#define N 3
#endif

int main() {
    int a[N], b[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int c[2*N];
    for (int i = 0; i < 2*N; i++) {
        if (i < N) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i - N];
        }
    }
    sort(c, c + 2*N);
    for (int i = 0; i < 2*N; i++) {
        cout << c[i] << ' ';
    }
    return 0;
}