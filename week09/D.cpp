#include <iostream>
#include <algorithm>

using namespace std;

int pr(int array[], int lb, int rb)
{
    int pivot = array[rb];
    int tr = lb;
    for (int i = lb; i < rb; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[tr]);
            tr++;
        }
    }
    swap(array[tr], array[rb]);
    return tr;
}
void qsort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = pr(array, start, end);
    qsort(array, start, pivot - 1);
    qsort(array, pivot + 1, end);
}

int main()
{
    int S = 0, N = 0;
    cin >> S >> N;
    int array[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    qsort(array, 0, N - 1);
    int t = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        if (t + array[i] <= S)
        {
            t = t + array[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}