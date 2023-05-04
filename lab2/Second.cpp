#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 500000
#endif

unsigned seed = 1000 - 7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N - 1);

int basic(int (&arr)[], int counter, int step)
{
    int t = 0;
    for (int i = 0; i < counter - step; i++)
    {
        if (arr[i] > arr[i + step])
        {
            swap(arr[i], arr[i + step]);
            t++;
        }
    }
    return t;
}

int sorting(int (&arr)[], int counter)
{
    int temp = 0;
    int n = int(counter / 1.247);
    while (n > 0)
    {
        temp = temp + basic(arr, counter, n);
        n = int(n / 1.2479);
    }
    return temp;
}

void randomize(int array[], int n)
{
    std::uniform_int_distribution<unsigned> dstr(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        array[i] = dstr(rng);
    }
}

int main()
{

    std::ofstream out;
    out.open("htht2.csv");
    out << "N,A,B" << std::endl;

    for (unsigned counter = 100; counter < N; counter += 5000)
    {
        int te = 0;
        int array[counter];
        randomize(array, counter);
        unsigned seed2 = counter * 7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter + 1);
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0; --cnt)
        {
            randomize(array, counter);
            te = sorting(array, counter);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_A_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        if (out.is_open())
        {
            out << counter << ',' << (float)time_span_A_r.count() / 10000 << ';' << te << std::endl;
        }
    }
    out.close();
    return 0;
}
