#include <iostream>
#include <cmath>
#include <algorithm>

#ifndef N
#define N 3
#endif

#ifndef M
#define M 3
#endif

using namespace std;

int main() {
    int a[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}