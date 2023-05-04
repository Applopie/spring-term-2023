#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int st = 0, end = 0;
    cin >> st >> end;
    int l = end - st + 1;
    int time = 0;
    for (int i = 1; i < num; i++)
    {
        cin >> st;
        if (st <= end)
        {
            st = end + 1;
        }
        cin >> time;
        if (time >= end)
        {
            end = time;
        }
        else
        {
            end = end;
        }
        if (end - st + 1 >= 0)
        {
            l = l + end - st + 1;
            ;
        }
        else
        {
            l = l;
        }
    }
    cout << l << endl;
    return 0;
}