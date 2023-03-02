#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void track(int& lha, int& rha) {
    if (lha > rha) {
        int a = lha;
        lha = rha;
        rha = a;
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i - 1]) {
            for (int j = i; j > 0; j--) {
                track(a[j - 1], a[j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    return 0;
}