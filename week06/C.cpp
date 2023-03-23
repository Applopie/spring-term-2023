#include <iostream>

using namespace std;

struct Time
{
    int hours;
    int min;
    int secs;
};

int main()
{
    Time data[3];
    (data[2]).hours = 0;
    (data[2]).min = 0;
    (data[2]).secs = 0;
    for (int i = 0; i < 2; i++)
    {
        cin >> (data[i]).hours >> (data[i]).min >> (data[i]).secs;
    }

    if ((data[0]).secs + (data[1]).secs >= 60)
    {
        (data[2]).min = ((data[0]).secs + (data[1]).secs) / 60;
        (data[2]).secs = ((data[0]).secs + (data[1]).secs) % 60;
    }
    else
    {
        (data[2]).secs = ((data[0]).secs + (data[1]).secs) % 60;
    }

    if ((data[0]).min + (data[1]).min + (data[2]).min >= 60)
    {
        (data[2]).hours = ((data[0]).min + (data[1]).min + (data[2]).min) / 60;
        (data[2]).min = ((data[0]).min + (data[1]).min + (data[2]).min) % 60;
    }
    else
    {
        (data[2]).min = ((data[0]).min + (data[1]).min + (data[2]).min) % 60;
    }

    (data[2]).hours = ((data[0]).hours + (data[1]).hours + (data[2]).hours) % 24;

    cout << (data[2]).hours << ':' << (data[2]).min << ':' << (data[2]).secs << endl;
    return 0;
}
