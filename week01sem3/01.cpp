#include <iostream>
#include <cmath>

using namespace std;

struct Point3D
{
    double x, y, z;
};

Point3D middle(Point3D const &a, Point3D const &b)
{
    Point3D c;
    c.x = max(a.x, b.x) - (fabs(a.x - b.x) / 2);
    c.y = max(a.y, b.y) - (fabs(a.y - b.y) / 2);
    c.z = max(a.z, b.z) - (fabs(a.z - b.z) / 2);
    return c;
}

double distance(Point3D const &a, Point3D const &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

Point3D com(Point3D const *const begin, Point3D const *const end)
{
    const Point3D *now = begin;
    Point3D c;
    double sum_x = 0, sum_y = 0, sum_z = 0, sum = 0;
    while (now != end)
    {
        sum++;
        sum_x += now->x;
        sum_y += now->y;
        sum_z += now->z;
        now = now + 1;
    }
    c.x = sum_x / sum, c.y = sum_y / sum, c.z = sum_z / sum;

    return c;
}

int main()
{
    Point3D a{9, 14, 17};
    Point3D b{5, 6, 9};
    Point3D c{0, 0, 0};
    c = middle(a, b);
    int n;
    cin >> n;
    Point3D *data = new Point3D[n];
    for (int i = 0; i < n; i++)
    {
        data[i].x = i;
        data[i].y = i + 1;
        data[i].z = 2 * i;
    }
    cout << c.x << ' ' << c.y << ' ' << c.z << endl;
    cout << distance(a, b) << endl;
    Point3D d{0, 0, 0};
    d = com(data, data + n);
    cout << d.x << ' ' << d.y << ' ' << d.z << endl;
    return 0;
}
