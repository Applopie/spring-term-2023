#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

int main()
{
    short int *ptr = nullptr;
    ptr = new short int[N];
    for (int i = 0; i < N; i++)
    {
        ptr[i] = i;
        cout << &ptr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << ptr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < N; i = i + 2)
    {
        ptr[i] = ptr[i] * ptr[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << ptr[i] << ' ';
    }
    return 0;
}