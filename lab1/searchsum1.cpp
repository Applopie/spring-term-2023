#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#ifndef N
#define N 70000
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

int funcbin(int array[N], int a) {
    int l = 0, r = N-1;
    while ((l < N - 1) and (r > 0)) {
        if (array[l] + array[r] == a) {
            return l, r;
        } 
        else if (array[l] + array[r] > a) {
            r--;
        } 
        else {
            l++;
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
        int b = a[10]  + a[35];
        //int b = -100;
        for (int j = 100; j > 0; j--) {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt != 0; --cnt) 
        funcbin(a, b);
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