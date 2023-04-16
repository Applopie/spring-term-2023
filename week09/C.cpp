#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    cin >> k;
    int arraym[k];
    for (int i = 0; i < k; i++)
    {
        cin >> arraym[i];
    }
    int M = 0, t = 0;
    cin >> M;
    for (int i = k; i > 0; i--)
    {
        while (M - arraym[i - 1] >= 0 and M >= 0)
        {
            t++;
            M = M - arraym[i - 1];
        }
    }
    t = t + M;
    cout << t << endl;
    return 0;
}