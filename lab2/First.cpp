#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 7
#endif

unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N-1);
int array[N];

void forwardstep(int (&arr)[N], int lb, int rb) {
    for (int i = lb; i < rb - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void backwardstep(int (&arr)[N], int lb, int rb) {
    for (int i = rb - 2; i > lb; i--) {
        if (arr[i] < arr[i - 1]) {
            swap(arr[i], arr[i - 1]);
        }
    }
}

void shaker_sort(int (&arr)[N], int lb, int rb) {
    while (lb < rb) {
        forwardstep(arr, lb, rb);
        backwardstep(arr, lb, rb);
        rb--;
        lb++;
    }
}

void randomize(int array[], int n){
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int i = 0; i < n; i++) {
        array[i] = dstr(rng);
    }
}

int main() {
    int key = 0;
    int array[N];

    std::ofstream out;
    out.open("shakershaker.csv");
    out << "N,A" << std::endl;
    
    
    for(unsigned counter = 100; counter < N; counter += 5000) {
        randomize(array, counter);
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter+1);  
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            strategy_A(array, counter, key);
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