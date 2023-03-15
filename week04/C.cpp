#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

void swapp(int (&arr)[], int n, int i) {
    if (2*n + 1 <= i & arr[n] < arr[2*n + 1]) {
        swap(arr[n], arr[2*n + 1]);
    }
    if (2*n + 2 <= i && arr[n] < arr[2*n + 2]) {
        swap(arr[n], arr[2*n + 2]);
    }
}

void cheops_sort(int (&arr)[N], int in, int sz) {
    if (in == 0) {
        return;
    }
    for (int i = in; i >= 0; i--) {
        swapp(arr, i, in);
    }
    swap(arr[0], arr[in]);
    hs(arr, in - 1, sz);
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cheops_sort(a, N - 1, N);
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
}