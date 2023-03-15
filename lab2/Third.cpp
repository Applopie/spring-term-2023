#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;

#ifndef N
#define N 500000
#endif

unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N-1);

void sort(int (&arr)[], int counter) {
    for (int i = 0; i < counter - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1])
        }
    }
}

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
}

int fibonacchi(int i) {
    if (i == 0 or i == 1) {
        return 1;
    }
    else {
        return fibonacchi(i - 1) + fibonacchi(i - 2);
    }
}

void randomize(int array[], int n){
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int i = 0; i < n; i++) {
        array[i] = dstr(rng);
    }
}

int main() {

    std::ofstream out;
    out.open("hthsh3.csv");
    out << "N,A" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 5000) {
        int array[counter];
        int t = 1;
        while (pow(2, t) - 1 < counter) {
            t += 1;
        }
        int a[t];
        for (int i = t; i > 0; i--) {
            a[i] = pow(2, i) - 1;
        }
        int h = 0; 
        while (fibonacchi(h) < counter) {
            h++;
        }
        int b[h];
        for (int i = h; i >= 0; i--) {
            b[i] = fibonacchi(i);
        }
        randomize(array, counter);
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter+1);  
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            sorting(array, counter);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_A_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        

        if (out.is_open()) {
            out << counter << ',' << (float) time_span_A_r.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}