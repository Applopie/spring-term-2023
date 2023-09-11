#include <iostream>
#include <cmath>

using namespace std;

struct Point3d
{
    double x = 0, y = 0, z = 0;
};

struct PointCloud
{
    Point3d *begin = nullptr;
    unsigned size = 0;
};

PointCloud create(int n)
{
    PointCloud fo;
    Point3d *data = new Point3d[n];
    fo.begin = data;
    fo.size = n;
    return fo;
}

void cancelcloud(PointCloud fo)
{
    if (fo.size == 0)
        return;
    delete[] cloud.begin;
    cloud.size = 0;
}

PointCloud createf2(PointCloud one, PointCloud two)
{
    int t = one.size + two.size;
    PointCloud newone;
    Point3d *data = new Point3d[t];
    for (int i = 0; i < one.size; i++)
    {
        data[i] = one.begin[i];
    }
    for (int j = two.size; j < one.size + two.size; j++)
    {
        data[j] = second.begin[j];
    }
    newone.size = t;
    newone.begin = data;
    cancelcloud(one);
    cancelcloud(two);
    return newone;
}

int main()
{
    int na, nb;
    cin >> na >> nb;
    PointCloud one = create(na);
    PointCloud two = create(nb);
    PointCloud three = createf2(one, two);
    return 0;
}