#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 500000
#endif

unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N-1);

void basic(int (&arr)[], int counter, int step) {
    for (int i = 0; i < counter - step; i++) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
        }
    }
}

void sorting(int (&arr)[], int counter) {
    int n = int(counter/1.247);
    while (n > 0) {
        basic(arr, counter, n);
        n = int(n/1.2479);
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
    out.open("hth.csv");
    out << "N,A" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 5000) {
        int array[counter];
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