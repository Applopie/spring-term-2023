#include <iostream>

using namespace std;

struct Students
{
    string name;
    int num;
};

int main()
{
    int N;
    Students data[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> (data[i]).name >> (data[i]).num;
    }
    cin >> N;
    for (int i = 0; i < 10; i++)
    {
        if ((data[i]).num > N)
        {
            cout << (data[i].name) << ' ';
        }
    }
    cout << endl;
    return 0;
}