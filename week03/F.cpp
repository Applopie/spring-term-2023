#include <iostream>
#include <cmath>

using namespace std;

#ifndef N
#define N 5
#endif

int binsearch(int (&array)[N]) {
    int it = 0, l = 0, r = N - 1;
    while (l < r) {
        it = (l + r)/2;
        if (array[it] == 1) {
            r = it;
        }
        else {
            l = it;
        }
        if (l == r - 1) {
            return l;
        }
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i ++) {
        cin >> a[i];
    }
    cout << binsearch(a) << endl;
    return 0;
}