#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif

int main()
{
    int *ptr = nullptr;
    ptr = new int[N];
    int a = 1, i = 0, fst = 0;
    while (a != 0)
    {
        cin >> a;
        if (i == 0)
        {
            fst = a;
        }
        ptr[0] = ptr[1];
        ptr[1] = a;
        if (i > 0 && ptr[1] != 0)
        {
            cout << ptr[0] - ptr[1] << ' ';
        }
        i++;
    }
    cout << endl;
    delete[] ptr;
    return 0;
}