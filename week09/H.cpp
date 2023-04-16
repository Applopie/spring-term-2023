#include <iostream>

using namespace std;

int bsh(int a[], int end, int rn)
{
    int t = 0;
    for (int i = 0; i < end - 1; i++)
    {
        if (a[i] > rn)
        {
            a[i + 1] = a[i + 1] + a[i] - rn;
            t = t + a[i] - rn;
            a[i] = rn;
        }
        else if (a[i] < rn)
        {
            if (a[i + 1] > rn)
            {
                a[i] = a[i] + a[i + 1] - rn;
                // t = t + a[i + 1] - rn;
                a[i + 1] = rn;
            }
        }
    }
    for (int i = end - 1; i > 0; i--)
    {
        if (a[i] > rn)
        {
            a[i - 1] = a[i - 1] + a[i] - rn;
            t = t + a[i] - rn;
            a[i] = rn;
        }
        else if (a[i] < rn)
        {
            if (a[i - 1] > rn)
            {
                a[i] = a[i] + a[i - 1] - rn;
                // t = t + a[i - 1] - rn;
                a[i - 1] = rn;
            }
        }
    }
    return t;
}

int main()
{
    int num = 0;
    cin >> num;
    int t = 0;
    int a[num];
    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
        t = t + a[i];
    }
    if (t % num != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int rnum = t / num;
        int ans = bsh(a, num, rnum);
        for (int i = 0; i < num; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}