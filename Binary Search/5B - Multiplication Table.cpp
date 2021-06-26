#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{

    int n;
    long long k;

    scanf("%d %lli", &n, &k);

    long long mid, l = 1, r = 1e10 + 1, sum, elm;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        sum = 0;
        for (int cnt = 1; cnt <= n; ++cnt)
        {
            elm = (long long)cnt * cnt;
            if (mid > elm)
            {
                elm = min((mid - 1) / cnt - (cnt - 1), n - cnt + 1);
                sum += 2 * elm - 1;
                if (sum > k)
                    break;
            }
            else
                break;
        }
        sum < k ? l = mid : r = mid;
    }

    printf("%lli", l);
    return 0;
}