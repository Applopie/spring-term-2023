#include <iostream>
#include <cmath>

using namespace std;

void one(float n, float m)
{
    if (n == 1)
    {
        cout << m << endl;
    }
    else if (int(m) % int(n) == 0)
    {
        cout << m / n << endl;
    }
    else
    {
        cout << ceil(m / n) << ' ';
        one(n * ceil(m / n) - m, m * ceil(m / n));
    }
}

int main()
{
    float n = 0, m = 0;
    cin >> n >> m;
    one(n, m);
    return 0;
}