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

void sort2d(int (&array)[N][M]) {
        int a[N*M], k = 0, t = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i + j + k] = array[i][j];
            }
            k = k + 2;
        }
        sort(a, a + N*M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                array[i][j] = a[t];
                t++;
            }
        }
    return;
}

int main() {
    int a[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    sort2d(a);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}