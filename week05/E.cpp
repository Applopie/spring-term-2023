#include <iostream>

using namespace std;

bool reserve_memory(int *&ptr, size_t N)
{
    if (ptr != nullptr)
    {
        return false;
    }
    ptr = new int[N];
    return true;
}

void free_memory(int *&ptr)
{
    delete[] ptr
}

int main()
{
    int N = 0;
    int *ptr = nullptr;
    cin >> N;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}