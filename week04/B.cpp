#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

int pr(int (&array)[N], int lb, int rb) {
    int pivot = array[rb];
    int tr = lb;
    for (int i = lb; i < rb; i++) {
        if (array[i] <= pivot) {
            swap (array[i], array[tr]);
            tr++;
        }
    }
    swap(array[tr], array[rb]);
    return tr;
}
void qs(int (&array)[N], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = pr(array, start, end);
    qs(array, start, pivot - 1);
    qs(array, pivot  + 1, end);
}
int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    qs(a, 0, N-1);
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}