#include <iostream>

using namespace std;

struct Atoms
{
    string name;
    int A;
    int Z;
    string react1, react2, react3;
};

struct Reactions
{
    string el;
    string react;
};

int main()
{
    int bp = -1, bm = 1, am = -4, az = -2;

    int N = 0;
    cin >> N;
    Atoms d[N];
    for (int i = 0; i < N; i++)
    {
        cin >> (d[i]).name >> (d[i]).A >> (d[i]).Z;
    }
    for (int i = 0; i < N; i++)
    {
        (d[i]).react1 = (d[i]).react2 = (d[i]).react3 = "NO DATA";
        int t1 = (d[i]).A - 4;
        int t2 = (d[i]).Z - 2;
        int t3 = (d[i]).Z - 1;
        int t4 = (d[i]).Z + 1;
        for (int j = 0; j < N; j++)
        {
            if ((d[j]).A == t1 && (d[j]).Z == t2)
            {
                (d[i]).react1 = (d[j]).name;
            }
            if ((d[j]).A == (d[i]).A && (d[j]).Z == t3)
            {
                (d[i]).react2 = (d[j]).name;
            }
            if ((d[j]).A == (d[i]).A && (d[j]).Z == t4)
            {
                (d[i]).react1 = (d[j]).name;
            }
        }
    }

    int N1 = 0;
    cin >> N1;
    Reactions data[N1];
    for (int i = 0; i < N1; i++)
    {
        cin >> (data[i]).el >> (data[i]).react;
    }
    string ans1 = "NO DATA", ans2 = "NO DATA", ans3 = "NO DATA";
    for (int i = 0; i < N1; i++)
    {
        int t = 0;
        for (int j = 0; j < N; j++)
        {
            if ((data[i]).el == (d[j]).name)
            {
                t = 1;
                ans1 = (d[j]).react1;
                ans2 = (d[j]).react2;
                ans3 = (d[j]).react3;
            }
        }
        if ((data[i]).react == "alpha")
        {
            if (t == 0)
            {
                cout << "NO DATA" << ' ';
            }
            else
            {
                cout << ans1 << ' ';
            }
        }
        if ((data[i]).react == "beta+")
        {
            if (t == 0)
            {
                cout << "NO DATA" << ' ';
            }
            else
            {
                cout << ans2 << ' ';
            }
        }
        if ((data[i]).react == "beta-")
        {
            if (t == 0)
            {
                cout << "NO DATA" << ' ';
            }
            else
            {
                cout << ans3 << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}