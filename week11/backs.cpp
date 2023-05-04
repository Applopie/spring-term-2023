#include <iostream>

using namespace std;

int zeros(int a)
{
    int ans = 0;
    while (a > 0)
    {
        if (a % 10 == 0)
        {
            ans++;
        }
        a = a / 10;
    }
    return ans;
}

int main()
{
    cout << zeros(500) << endl;
}