#include <cstdio>
#include <algorithm>

int n, k, *arr;

using namespace std;

bool good(int d)
{
    int tmp = 1, idx = 0;
    while (idx < n)
    {
        idx = upper_bound(arr + idx + 1, arr + n, arr[idx] + d - 1) - arr;
        if (idx != n)
            if (++tmp == k)
                return 1;
    }

    return 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    arr = new int[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    int mid, l = 1, r = arr[n - 1] - arr[0] + 1;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        good(mid) ? l = mid : r = mid;
    }

    printf("%d", l);

    return 0;
}