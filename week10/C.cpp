#include <iostream>

using namespace std;

int main()
{
    int l = 0;
    cin >> l;
    int price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};
    int count[10];
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        while (l - 10 + i >= 0)
        {
            l = l - 10 + i;
            if (i == 0)
            {
                count[9]++;
            }
            else if (i == 1)
            {
                count[2]++;
                count[5]++;
            }
            else if (i == 2)
            {
                count[1]++;
                count[5]++;
            }
            else if (i == 3)
            {
                count[0]++;
                count[5]++;
            }
            else if (i == 4)
            {
                count[5]++;
            }
            else if (i == 5)
            {
                count[1]++;
                count[2]++;
            }
            else if (i == 6)
            {
                count[1] = count[1] + 2;
            }
            else if (i == 7)
            {
                count[2]++;
            }
            else if (i == 8)
            {
                count[1]++;
            }
            else if (i == 9)
            {
                count[0]++;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (count[i] != 0)
        {
            count[i]--;
            cout << i + 1 << ' ';
        }
    }
    return 0;
}