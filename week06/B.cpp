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

void swap(int lf, int right)
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
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if ((data[j]).num >= (data[j + 1]).num)
            {
                if ((data[j]).num == (data[j + 1]).num)
                {
                    if (((data[j]).name).compare((data[j]).name) > 0)
                    {
                        swapst((data[j]).name, (data[j]).name);
                    }
                }
                else
                {
                    swap((data[j]).num, (data[j + 1]).num);
                    swapst((data[j]).name, (data[j]).name);
                }
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