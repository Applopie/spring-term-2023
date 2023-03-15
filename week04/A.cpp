#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 5
#endif

void gnome_sort(int (&a)[N]) {
    int i = 1;
    while (i < N) {
        int t = 0;
        if (a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
            t = 1;
            if (i > 1) {
                i--;
            }
            else { 
                i++;
            }
        }
        if (t == 0) {
            i++;
        }
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    gnome_sort(a);
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    return 0;
}