#include <iostream>

using namespace std;

struct lines
{
    int start, end;
};

int main()
{
    int N;
    cin >> N;
    if (N == 1)
    {
        lines d[1];
        cin >> (d[0]).start >> (d[0]).end;
        cout << "YES" << endl;
    }
    else
    {
        lines d[N];
        for (int i = 0; i < N; i++)
        {
            cin >> (d[i]).start >> (d[i]).end;
        }
        int t = 0;
        int st_c = 0, end_c = 0;
        for (int i = 0; i < N; i++)
        {
            if ((d[i]).end < (d[i]).start)
            {
                swap((d[i]).end, (d[i]).start);
            }
        }
        for (int i = 0; i < N - 1; i++)
        {
            if ((d[i]).start < (d[i + 1]).start)
            {
                st_c = (d[i + 1]).start;
            }
            else
            {
                st_c = (d[i]).start;
            }

            if ((d[i]).end > (d[i + 1]).end)
            {
                end_c = (d[i + 1]).end;
            }
            else
            {
                end_c = (d[i]).end;
            }

            if (end_c < st_c)
            {
                t = 1;
            }
        }
        if (t == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}