#include <iostream>

using namespace std;

int main()
{
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    int a1 = s1.length();
    int a2 = s2.length();
    if (a1 < a2)
    {
        int a3 = a1;
        a1 = a2;
        a2 = a3;
    }
    int a[a1][a2];
    int lenght = 0;
    int t = 0;
    for (int i = 0; i < a2; i++)
    {
        t = 0;
        for (int j = 0; j < a1; j++)
        {
            if (s2[i] == s1[j] && t != 1)
            {
                t = 1;
                lenght++;
            }
        }
    }
    cout << lenght << endl;
    return 0;
}