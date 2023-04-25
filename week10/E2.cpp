#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    int a1 = s1.length();
    int a2 = s2.length();
    if (s1.length() < s2.length())
    {
        swap(s1, s2);
    }
    int zero[1000];
    int one[1000];
    for (int i = 0; i < a2; i++)
    {
        zero[i] = 0;
        one[i] = 0;
    }
    for (int i = 1; i <= a1; i++)
    {
        one[0] = 0;
        for (int j = 1; j <= a2; j++)
        {
            zero[j] = one[j];
            if (s1[i] == s2[j])
            {
                one[j] = zero[j - 1] + 1;
            }
            else
            {
                if (zero[j] >= one[j - 1])
                {
                    one[j] = zero[j];
                }
                else if (zero[j] < one[j - 1])
                {
                    one[j] = one[j - 1];
                }
            }
        }
    }
    cout << (one[a2] / s2.length()) * 100 << endl;
    return 0;
}