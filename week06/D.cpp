#include <iostream>
#include <algorithm>

using namespace std;

struct Coor
{
    float x, y;
    float xx, yy;
};

string street(float x, float y, float xx, float yy, float h, float t, float hh, float tt)
{
    float a, b, a1, b1;
    a = (y - yy) / (x - xx);
    b = y - a * x;
    a1 = (t - tt) / (h - hh);
    b1 = t - a1 * h;
    if (xx < x)
    {
        swap(x, xx);
    }
    if (tt < t)
    {
        swap(t, tt);
    }
    if (hh < h)
    {
        swap(h, hh);
    }
    if (yy < y)
    {
        swap(y, yy);
    }
    int f = 0;
    for (int i = x; i <= xx; i++)
    {
        for (int j = h; j <= hh; j++)
        {
            if (a * i + b == a1 * j + b1)
            {
                f = 1;
                return "NO";
            }
        }
    }
    if (f == 0)
    {
        return "YES";
    }
}

int main()
{
    Coor d[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> (d[i]).x >> (d[i]).y >> (d[i]).xx >> (d[i]).yy;
    }
    cout << street((d[0]).x, (d[0]).y, (d[0]).xx, (d[0]).yy, (d[1]).x, (d[1]).y, (d[1]).xx, (d[1]).yy) << endl;
    return 0;
}
