#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int hm = 0;
    cin >> hm;
    if (hm == 2)
    {
        int st = 0, end = 0;
        cin >> st >> end;
        cout << end - st << endl;
    }

    else
    {
        int al[100];
        int lenght = 0;
        int l = 0, l1 = 0;
        cin >> l;
        for (int i = 0; i < hm - 1; i++)
        {
            cin >> l1;
            al[i] = l1 - l;
            l = l1;
        }
        lenght = al[0] + al[hm - 2];
        al[0] = 10000;
        al[hm - 2] = 100000;
        sort(al + 1, al + hm - 2);
        for (int i = 0; i < (hm - 2) / 2; i++)
        {
            lenght = lenght + al[i + 1];
        }
        cout << lenght << endl;
    }
    return 0;
}