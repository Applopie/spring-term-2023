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
    int l = 0;
    cin >> l;
    int t[2][300];
    cin >> t[0][0];
    int num = 0;
    for (int i = 1; i < l; i++)
    {
        cin >> num;
        t[0][i] = t[i - 1] * num;
    }
    for (int i = 1; i < l; i++)
    {
        if (i != 1)
        {
            for (int j = 0; j < l; j++)
            {
                t[1][j] = t[0][j];
            }
        }
        cin >> num;
        t[1][0] = t[0][0] * num;
        for (int q = 1; q < l; q++)
        {
            cin << num;
            if zeros (t[0][q] * num)
                < zeros(t[1][q - 1] * num)
                {
                    t[1][q] = t[0][q] * num;
                }
            else
            {
                t[1][q] = t[1][q - 1] * num;
            }
        }
    }
    cout << zeros(t[1][l - 1]) << endl;
    return 0;
}