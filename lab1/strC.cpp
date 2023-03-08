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
int array[N];



int search(int array[], int n, int sr) {
    for (int i = 0; i < n; i++) {
        if (array[i] == sr) {
            return i;
        }
    }
    return -1;
}

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
    return;
}

void strategy_C(int array[], int darr[], int n, int sr){
    int i = search(array, n, sr);
    darr[i + 1]++;
    if (darr[i + 1] > darr[i]) {
        swap(array[i], array[i - 1]);
        swap(darr[i + 1], darr[i]);
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

    std::ofstream out;
    out.open("strategy_C.csv");
    out << "N,A,B" << std::endl;
    
    
    for(unsigned counter = 100; counter < N; counter += 5000) {
        int array[counter];
        int darr[counter+1] = {0};
        randomize(array, counter);
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter+1);  
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            strategy_C(array, darr, counter, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_A_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        
        randomize(array, counter);
        auto begin_n = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            int key_n = array[0];
            for (int i = 0; i < counter; i++) {
                if (i%4 != 0) {
                    if (key == array[i]) {
                        key = key_n;
                    }
                }
            }
            strategy_C(array, darr, counter, key);
        }
        auto end_n = std::chrono::steady_clock::now();
        auto time_span_A_n = std::chrono::duration_cast<std::chrono::microseconds>(end_n - begin_n); 

        if (out.is_open()) {
            out << counter << ',' << (float) time_span_A_r.count()/10000 << ',' << (float) time_span_A_n.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}