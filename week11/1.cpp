#include <iostream>
#include <cmath>

using namespace std;

int ten_four(int a)
{
    int t = 1;
    int ans = 0;
    while (a > 0)
    {
        ans = ans + (a % 4) * t;
        t = t * 10;
        a = a / 4;
    }
    return ans;
}

int seven_ten(int b)
{
    int t = 0;
    int ans = 0;
    while (b > 0)
    {
        ans = ans + (b % 10) * pow(7, t);
        t++;
        b = b / 10;
    }
    return ans;
}

int main()
{
    int a = 0;
    cin >> a;
    int sum = 0;
    int b = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        sum = sum + seven_ten(b);
    }
    cout << ten_four(sum) << endl;
    return 0;
}