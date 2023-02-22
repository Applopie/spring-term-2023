#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#ifndef N
#define N 100
#endif

using namespace std;

int func(int (&array)[N], int a) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((i + j) == a) {
                return i, j;
            }
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