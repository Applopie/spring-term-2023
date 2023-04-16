#include <iostream>

using namespace std;

int bsh(int a[], int end, int rn, int turns)
{
    int temp = 0, tempt = 0;
    if (a[0] > rn)
    {
        a[1]++;
        a[0]--;
        temp = 1;
    }
    if (a[end - 1] > rn)
    {
        a[end - 2]++;
        a[end - 1]--;
    }
    for (int i = 1; i < end - 1; i++)
    {
        if (a[i] > rn)
        {
            if (a[i + 1] >= rn and temp != 1)
            {
                a[i - 1]++;
            }
            else
            {
                a[i + 1]++;
            }
        }
    }
    for (int i = 0; i < end; i++)
    {
        if (a[i] != rn)
        {
            tempt = 1;
        }
    }
    turns++;
    while (tempt == 1)
    {
        bsh(a, end, rn, turns);
    }
    return turns;
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
        int ind = 0;
        for (int i = 0; i < num; i++)
        {
            if (a[i] != rnum)
            {
                ind = 1;
            }
        }
        int ans = 0;
        if (ind == 0)
        {
            ans = 0;
        }
        else
        {
            ans = bsh(a, num, rnum, 0);
            for (int i = 0; i < num; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}