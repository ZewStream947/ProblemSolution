#include <cstdio>
#include <algorithm>

int main()
{
    int n;
    long long k;
    scanf("%d %lli", &n, &k);

    int a[n], b[n];

    for (int index = 0; index < n; scanf("%d", &a[index++]))
        ;
    for (int index = 0; index < n; scanf("%d", &b[index++]))
        ;

    std::sort(a, a + n);
    std::sort(b, b + n);

    long long mid, l = 0, r = 2e9 + 1, sum;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        sum = 0;
        for (int index = 0, idx = n - 1; index < n; ++index)
        {
            while (idx >= 0 && a[index] + b[idx] >= mid)
                --idx;
            sum += idx + 1;
            if (sum >= k || idx == -1)
                break;
        }
        sum < k ? l = mid : r = mid;
    }

    printf("%lli", l);
    return 0;
}