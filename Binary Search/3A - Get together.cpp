#include <iostream>

using namespace std;

int n;
struct status
{
    int x, v;
} * arr;

pair<double, double> getIntersect(double a, double b, double x, double y)
{
    return make_pair(max(a, x), min(b, y));
}

bool isIntersect(double a, double b, double x, double y)
{
    return b >= x && a <= y;
}

bool good(double t)
{
    pair<double, double> prev = {-1e9, 1e9};
    for (int index = 0; index < n; ++index)
    {
        double l = (double)(arr[index].x - (double)arr[index].v * t),
               r = (double)(arr[index].x + (double)arr[index].v * t);
        if (!isIntersect(l, r, prev.first, prev.second))
            return 0;
        prev = getIntersect(l, r, prev.first, prev.second);
    }
    return 1;
}

int main()
{
    scanf("%d", &n);

    arr = new status[n];

    for (int index = 0; index < n; ++index)
        scanf("%d %d", &arr[index].x, &arr[index].v);

    double mid, l = 0, r = 1e10;
    pair<int, int> prev;

    for (int cnt = 100; cnt; --cnt)
    {
        mid = (l + r) / 2;
        good(mid) ? r = mid : l = mid;
    }

    printf("%lf", r);
    return 0;
}