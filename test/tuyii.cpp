#include <iostream>
#include <string>

using namespace std;

int solution(string roman)
{
    int res = 0;
    int a = roman.length();
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        if (roman[i] == 'I')
        {
            arr[i] = 1;
        }
        else if (roman[i] == 'V')
        {
            arr[i] = 5;
        }
        else if (roman[i] == 'X')
        {
            arr[i] = 10;
        }
        else if (roman[i] == 'L')
        {
            arr[i] = 50;
        }
        else if (roman[i] == 'C')
        {
            arr[i] = 100;
        }
        else if (roman[i] == 'D')
        {
            arr[i] = 500;
        }
        else if (roman[i] == 'M')
        {
            arr[i] = 1000;
        }
    }
    for (int i = 0; i < a - 1; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            arr[i] = arr[i] - 2 * arr[i];
        }
        res = res + arr[i];
    }
    return res + arr[a - 1];
}

int main()
{
    cout << solution("MMVIII") << endl;
    return 0;
}