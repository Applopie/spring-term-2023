#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>

#ifndef N
#define N 100
#endif

using namespace std;

int func(int (&array)[N], int a) {
    int l = 0, r = N - 1, it = 0;
    sort(array, array + N);
    while (l < r) {
        it = (l + r)/2;
        if (array[it] == a) {
            return it;
        }
        else if (array[it] > a) {
            r = it - 1;
        }
        else {
            l = it + 1;
        }
    }
    return -1;
}

int main() {
    int a[N];
    
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; --cnt) 
    func();
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
    cout << "\n\n";
    cout << time_span.count() << endl;
    return 0;
}