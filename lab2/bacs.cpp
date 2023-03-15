#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 8
#endif

void basic(int (&arr)[], int counter, int step) {
    for (int i = 0; i < counter - step; i++) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
        }
    }
}

void shell(int (&arr)[], int counter) {
    int a = counter;
    while (a >= 1) {
        basic(arr, counter, a);
        a = a/2;
    }
}

void shell2(int (&arr)[], int counter, int (&a)[], int hpcounter) {
    for (int i = 0; i < hpcounter; i++) {
        basic(arr, counter, a[i]);
    }
    basic(arr, counter, 1);
}

int fibonacchi(int i) {
    if (i == 0 or i == 1) {
        return 1;
    }
    else {
        return fibonacchi(i - 1) + fibonacchi(i - 2);
    }
}

int main() {
    int arr[N];
    int t = 1;
        while (pow(2, t) - 1 < N) {
            t += 1;
        }
        int a[t - 1];
        for (int i = t - 1; i > 0; i--) {
            a[t - 1 - i] = pow(2, i) - 1;
        }
        int h = 0; 
        while (fibonacchi(h) < N) {
            h++;
        }
        int b[h];
        for (int i = h; i >= 0; i--) {
            b[i] = fibonacchi(i);
        }
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //shell2(arr, N, a, t - 1);
    basic(arr, N, 1);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}