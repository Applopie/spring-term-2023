#include <iostream>

using namespace std;

int main()
{
    int needed = 0;
    cin >> needed;
    long long int a[3]{1, 1, 2};
    for (int i = 3; i <= needed; i++)
    {
        a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3];
    }
    cout << a[needed % 3] * a[needed % 3] << endl;
    return 0;
}