#include <cstdio>

#define min(a, b) (a < b ? a : b)

int *arr, k, n;

bool good(long long x)
{
    long long slots = x * k;
    for (int index = 0; index < n && slots > 0; ++index)
        slots -= min(x, (long long)arr[index]);
    return slots <= 0;
}

int main()
{
    scanf("%d %d", &k, &n);

    arr = new int[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    long long mid, l = 0, r = 5e10;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        good(mid) ? l = mid : r = mid;
    }

    printf("%lli", l);
    return 0;
}