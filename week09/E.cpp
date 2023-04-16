#include <iostream>

using namespace std;

int main()
{
    int dist = 0, time = 0;
    cin >> dist >> time;
    int num = 0;
    cin >> num;
    int ch[num];
    int t = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> ch[i];
    }
    if (time > dist)
    {
        cout << 0 << endl;
    }
    else
    {
        if (ch[0] > time)
        {
            t = -1;
        }
        for (int i = 0; i < num - 1; i++)
        {
            if (ch[i + 1] - ch[i] > time)
            {
                t = -1;
            }
        }
        if (t != -1)
        {
            t = 0;
            int rdist = 0;
            for (int i = 0; i < num - 1; i++)
            {
                if (ch[i + 1] - rdist > time)
                {
                    rdist = ch[i];
                    t++;
                }
            }
            t = t + 1;
        }
    }
    cout << t << endl;
    return 0;
}