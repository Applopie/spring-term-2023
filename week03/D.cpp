#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

bool comp(int& a, int& b) {
    return a >= b;
}

int main() {
    int a[N];
    int k = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N, comp);
    for (int j = 0; j < N; j++) {
        if (a[j] >= 0) {
            k++;
        }
    }
    sort(a, a + k);
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
