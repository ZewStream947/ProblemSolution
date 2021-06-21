#include <cstdio>

int n, k, *arr;

bool isGood(double x)
{
    int s = 0;
    for (int index = 0; index < n; ++index)
    {
        s += (int)((double)arr[index] / x);
        if (s >= k)
            return 1;
    }
    return s >= k;
}

int main()
{
    scanf("%d %d", &n, &k);

    arr = new int[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    double l = 0, r = 1e7, mid;
    for (int cnt = 100; cnt; --cnt)
    {
        mid = (l + r) / 2.0;
        isGood(mid) ? l = mid : r = mid;
    }

    printf("%lf", mid);
    return 0;
}