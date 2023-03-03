#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

void swapp(int (&arr)[], int n, int i) {
    int hd = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[hd]) {
        hd = l;
    }
    if (r < n && arr[r] > arr[hd]) {
        hd = r;
    }
    if (hd != i) {
        swap(arr[i], arr[hd]);
        swapp(arr, n, hd);
    }
    if (l < n && r < n && arr[l] < arr[r]) {
        swap(arr[r], arr[l]);
    }
}

void hs(int (&arr)[], int n) {
    for (int i = n/2 - 1; i > 0; i--) {
        swapp(arr, n, i);
    }
    for (int i = N - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        swapp(arr, n, 0);
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    hs(a, N);
    for (int i = N - 1; i >= 0; i--) {
        cout << a[i] << ' ';
    }
}