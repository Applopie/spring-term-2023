#include <iostream>
#include <algorithm>

using namespace std;

void swapst(string lf, string right)
{
    string t;
    t = lf;
    lf = right;
    right = t;
}

void swap(itn lf, int right)
{
    int t;
    t = lf;
    lf = right;
    right = t;
}

struct Students
{
    string name;
    int num;
};

int main()
{
    int n;
    int m;
    cin >> n;
    Students data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> (data[i]).name >> (data[i]).num;
    }
    cin >> m;
    int t = 5;
    while (t != 0)
    {
        t = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if ((data[i + 1]).num < (data[i]).num)
            {
                swapst((data[i + 1]).name, (data[i]).name);
                swap((data[i + 1]).num, (data[i]).num);
                t++;
            }
            if ((data[i + 1]).num == (data[i]).num)
            {
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((data[i]).num > m)
        {
            cout << (data[i]).name << ' ';
        }
    }
    cout << endl;
    return 0;
}