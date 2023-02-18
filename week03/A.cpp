#include <iostream>
#include <cmath>
using namespace std;

#ifndef N
#define N 3
#endif

void swap(int& lha, int& rha) {
    int a = lha;
    lha = rha;
    rha = a;
}

int main() {
    int a[N] = {1, 2, 3};
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int t = N;
    for (int j = 0; j < N/2; j++) {
        swap(a[j], a[N - 1 - j]);
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}