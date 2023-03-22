// at least i've tried
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

void forwardstep(int (&arr)[N], int lb, int rb)
{
    for (int i = lb; i < rb - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void backwardstep(int (&arr)[N], int lb, int rb)
{
    for (int i = rb - 2; i > lb; i--)
    {
        if (arr[i] < arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
    }
}

void shaker_sort(int (&arr)[N], int lb, int rb)
{
    while (lb < rb)
    {
        forwardstep(arr, lb, rb);
        backwardstep(arr, lb, rb);
        rb--;
        lb++;
    }
}

int main()
{
    unsigned ansa1[5] = {10, 0, 5, 3, 11};

    unsigned ansa2[10] = {22, 3, 3, 11, 1, 7, 19, 101, 11, 109};

    unsigned ansa3[15] = {3, 3, 3, 3, 3, 6, 5, 6, 7, 0, 0, 7, 3, 5, 101};

    unsigned ansa4[20] = {10, 2, 4, 12, 64, 70, 64, 2, 13, 5, 76, 89, 67, 4, 44, 34, 12, 65, 32, 98};

    unsigned ansa5[25] = {15, 33, 3, 44, 1, 15, 45, 39, 67, 3, 97, 54, 43, 23, 45, 101, 4, 193, 65, 32, 5, 67, 4, 8, 99, 44, 967};

    unsigned ansa6[30] = {15, 69, 53, 50, 0, 7, 4, 2, 1, 76, 212, 234, 211, 334, 9, 6, 4, 3, 1, 90, 87, 45, 23, 11, 400,
                          567, 653, 234, 120, 890};

    unsigned ansa7[35] = {5, 67, 12, 21, 8, 54, 23, 56, 0, 345, 77, 67, 90, 456, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                          342, 21, 15, 870, 64, 1, 1, 1, 56, 965};

    unsigned ansa8[40] = {5, 67, 12, 21, 8, 54, 23, 56, 0, 345, 77, 67, 90, 456, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                          342, 21, 15, 870, 64, 1, 1, 1, 56, 396, 965, 65, 13, 4, 1025};

    unsigned ansa9[45] = {4, 3, 12, 15, 4, 6, 54, 17, 10, 45, 45, 12, 12, 56, 77, 78, 12, 13, 1, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                          2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 90, 65, 33, 3, 87, 21, 10, 5, 4, 3, 8, 6, 98};

    unsigned ansa10[50] = {4, 3, 12, 15, 4, 6, 6, 17, 10, 45, 45, 12, 12, 56, 77, 90, 12, 13, 14, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                           2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 98, 65, 33, 37, 87, 21, 10, 5, 4, 3, 8, 6, 12, 22, 33, 44, 22, 778};

    unsigned a1[5] = {10, 11, 0, 5, 3};

    unsigned a2[10] = {22, 101, 3, 3, 11, 1, 7, 19, 109, 11};

    unsigned a3[15] = {3, 3, 3, 3, 3, 6, 6, 5, 7, 7, 0, 0, 101, 3, 5};

    unsigned a4[20] = {10, 12, 2, 4, 64, 70, 76, 64, 2, 13, 5, 89, 98, 67, 4, 44, 34, 12, 65, 32};

    unsigned a5[25] = {15, 45, 33, 3, 44, 1, 15, 67, 39, 97, 3, 101, 54, 43, 23, 45, 967, 4, 193, 65, 32, 5, 67, 4, 8, 99, 44};

    unsigned a6[30] = {15, 69, 76, 53, 50, 0, 7, 4, 2, 1, 334, 212, 234, 211, 400, 9, 6, 4, 3, 1, 90, 87, 45, 23, 11, 890,
                       567, 653, 234, 120};

    unsigned a7[35] = {67, 5, 345, 12, 21, 8, 54, 23, 56, 0, 456, 77, 67, 90, 965, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                       342, 21, 15, 870, 64, 1, 1, 1, 56};

    unsigned a8[40] = {67, 5, 345, 12, 21, 8, 54, 23, 56, 0, 456, 77, 67, 90, 965, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                       342, 21, 15, 870, 64, 1, 1, 1, 56, 396, 1025, 65, 13, 4};

    unsigned a9[45] = {4, 12, 3, 56, 15, 4, 6, 54, 17, 10, 45, 45, 12, 12, 77, 78, 90, 12, 13, 1, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                       2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 98, 65, 33, 3, 87, 21, 10, 5, 4, 3, 8, 6};

    unsigned a10[50] = {4, 12, 3, 56, 15, 4, 6, 6, 17, 10, 45, 45, 12, 12, 77, 778, 90, 12, 13, 14, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                        2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 98, 65, 33, 37, 87, 21, 10, 5, 4, 3, 8, 6, 12, 22, 33, 44, 22};

    unsigned answa1[5] = {0, 10, 11, 3, 5};

    unsigned answa2[10] = {1, 22, 101, 3, 3, 11, 7, 11, 19, 109};

    unsigned answa3[15] = {0, 3, 3, 3, 3, 3, 6, 6, 5, 7, 7, 0, 3, 101, 5};

    unsigned answa4[20] = {10, 12, 2, 4, 64, 70, 76, 64, 2, 13, 5, 89, 98, 67, 4, 44, 34, 12, 65, 32};

    unsigned answa5[25] = {15, 45, 33, 3, 44, 1, 15, 67, 39, 97, 3, 101, 54, 43, 23, 45, 967, 4, 193, 65, 32, 5, 67, 4, 8, 99, 44};

    unsigned answa6[30] = {15, 69, 76, 53, 50, 0, 7, 4, 2, 1, 334, 212, 234, 211, 400, 9, 6, 4, 3, 1, 90, 87, 45, 23, 11, 890,
                           567, 653, 234, 120};

    unsigned answa7[35] = {67, 5, 345, 12, 21, 8, 54, 23, 56, 0, 456, 77, 67, 90, 965, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                           342, 21, 15, 870, 64, 1, 1, 1, 56};

    unsigned answa8[40] = {67, 5, 345, 12, 21, 8, 54, 23, 56, 0, 456, 77, 67, 90, 965, 1, 23, 20, 245, 7, 15, 56, 87, 32, 78, 101,
                           342, 21, 15, 870, 64, 1, 1, 1, 56, 396, 1025, 65, 13, 4};

    unsigned answa9[45] = {4, 12, 3, 56, 15, 4, 6, 54, 17, 10, 45, 45, 12, 12, 77, 78, 90, 12, 13, 1, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                           2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 98, 65, 33, 3, 87, 21, 10, 5, 4, 3, 8, 6};

    unsigned answa10[50] = {4, 12, 3, 56, 15, 4, 6, 6, 17, 10, 45, 45, 12, 12, 77, 778, 90, 12, 13, 14, 65, 66, 64, 67, 63, 0, 0, 0, 1,
                            2, 11, 76, 72, 23, 43, 84, 54, 56, 90, 98, 65, 33, 37, 87, 21, 10, 5, 4, 3, 8, 6, 12, 22, 33, 44, 22};

    forwardstep(a1, 0, 4);
    forwardstep(a2, 0, 9);
    forwardstep(a3, 0, 14);
    forwardstep(a4, 0, 19);
    forwardstep(a5, 0, 24);
    forwardstep(a6, 0, 29);
    forwardstep(a7, 0, 34);
    forwardstep(a8, 0, 39);
    forwardstep(a9, 0, 44);
    forwardstep(a10, 0, 49);

    int marker = 0;
    if (std::equal(array1, array1 + 10, ans_array1))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array2, array2 + 50, ans_array2))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array3, array3 + 5, ans_array3))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array4, array4 + 25, ans_array4))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array5, array5 + 33, ans_array5))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array6, array6 + 42, ans_array6))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array7, array7 + 17, ans_array7))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array8, array8 + 8, ans_array8))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (marker == 8)
    {
        cout << "function works correctly";
    }
    else
    {
        cout << "something wrong " << marker;
    }

    backwardstep(a1, 0, 4);
    backwardstep(a2, 0, 9);
    backwardstep(a3, 0, 14);
    backwardstep(a4, 0, 19);
    backwardstep(a5, 0, 24);
    backwardstep(a6, 0, 29);
    backwardstep(a7, 0, 34);
    backwardstep(a8, 0, 39);
    backwardstep(a9, 0, 44);
    backwardstep(a10, 0, 49);

    int marker = 0;
    if (std::equal(array1, array1 + 10, ans_array1))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array2, array2 + 50, ans_array2))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array3, array3 + 5, ans_array3))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array4, array4 + 25, ans_array4))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array5, array5 + 33, ans_array5))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array6, array6 + 42, ans_array6))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array7, array7 + 17, ans_array7))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (std::equal(array8, array8 + 8, ans_array8))
    {
        marker++;
    }
    else
    {
        marker = 0;
    }

    if (marker == 8)
    {
        cout << "function works correctly";
    }
    else
    {
        cout << "something wrong " << marker;
    }

    return 0;
}