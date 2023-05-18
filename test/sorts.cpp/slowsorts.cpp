#include <iostream>
#include <algorithm>

using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// шейкерная сортировка -- +/- сортировка пузырьком но в обе стороны
// сортировка расческой
// гномья
// сортировка вставками

int main()
{
    int a[5]{4, 6, 4, 2, 1};
    bubblesort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}