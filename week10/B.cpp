#include <iostream>

using namespace std;

int main()
{
    int l = 0;
    cin >> l;
    int pr = 0;
    int price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};
    for (int i = 0; i < 10; i++)
    {
        while (l - 10 + i >= 0)
        {
            pr = pr + price[i];
            l = l - 10 + i;
        }
    }
    cout << pr << endl;
    return 0;
}