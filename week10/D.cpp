#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    cin >> x;
    long int a[4]{1, 1, 2, 4};
    for (int i = 4; i <= x; i++)
    {
        a[i % 4] = a[(i - 1) % 4] + a[(i - 2) % 4] + a[(i - 3) % 4];
    }
    cout << a[x % 4] << endl;
    return 0;
}