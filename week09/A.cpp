#include <iostream>

using namespace std;

int main()
{
    int arraym[6]{98, 63, 49, 28, 7};
    int M = 0, t = 0;
    cin >> M;
    for (int i = 0; i < 5; i++)
    {
        while (M - arraym[i] > 0 and M != 0)
        {
            t++;
            M = M - arraym[i];
        }
    }
    t = t + M;
    cout << t << endl;
    return 0;
}