#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>

#ifndef N
#define N 1000000
#endif

using namespace std;

int func(int (&array)[N], int a) {
    for (int i = 0; i < N; i++) {
        if (array[i] == a) {
            return i;
        }
    }
    return -1;
}

int funcbin(int (&array)[N], int a) {
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
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, N);

    for (int i = 0; i < N; i++) {
        a[i] = dstr(rng);
    }
    int t = 0, tt = 0;
    //int b = dstr(rng);
    int b = -100;
    for (int j = 40; j > 0; j--) {
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; --cnt) 
    func(a, b);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
    cout << "\n\n";
    cout << time_span.count() << endl;
    t ++;
    tt = tt + time_span.count();
    }
    cout << tt/t << endl;
    return 0;
}