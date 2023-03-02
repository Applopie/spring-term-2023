#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>

#ifndef N
#define N 300000
#endif

using namespace std;

int func(int (array)[N], int a) {
    for (int i = 0; i < N; i++) {
        if (array[i] == a) {
            return i;
        }
    }
    return -1;
}

int funcbin(int (&array)[N], int l, int r, int a) {
    int it = (l + r) / 2.;
    if (array[l] == a) {
        return array[l];
    } 
    else if (array[r] == a) {
        return array[r];
    } 
    else if (array[l + 1] == array[r]){
        return -1;
    } 
    else if (array[r] < a) {
        return -1;
    }
    else if (array[l] > a) {
        return -1;
    } 
    else if (array[it] < a) {
        return funcbin(array, it, r, a);
    }
     else if (array[it] > a) {
        return  funcbin(array, l, it, a);
    }
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
    int b = dstr(rng);
    //int b = -100;
    sort(a, a + N);
    for (int j = 100; j > 0; j--) {
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 1000000; cnt != 0; --cnt) 
    funcbin(a, 0, N - 1, b);
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