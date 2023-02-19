#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if (N == 1) {
        cout << a[0] << endl;
    }
    sort(a, a + N);
    if (a[0] != a[1]) {
        cout << a[0] << endl;
    }
    if (a[N - 1] != a[N - 2]) {
        cout << a[N - 1] << endl;
    }
    for (int i = 1; i < N - 1; i++) {
        if (a[i] != a[i -1] and a[i] != a[i + 1]) {
            cout << a[i] << endl;
        }
    }
    return 0;
}