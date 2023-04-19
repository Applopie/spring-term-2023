#include <iostream>

using namespace std;

int hl(int a[], int size, int rinum)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] - rinum >= ans)
        {
            ans = a[i] - rinum;
        }
    }
    return ans;
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
        cout << hl(a, num, rnum) << endl;
    }
    return 0;
}