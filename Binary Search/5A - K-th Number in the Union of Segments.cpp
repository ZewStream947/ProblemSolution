#include <iostream>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    ii seg[n];

    for (int index = 0; index < n; ++index)
        scanf("%d %d", &seg[index].first, &seg[index].second);

    long long l = -2e9, mid, r = 2e9 + 1, sum;

    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        sum = 0;
        for (int index = 0; index < n; ++index)
            if (seg[index].first < mid)
            {
                sum += min(mid - seg[index].first, (long long)seg[index].second - seg[index].first + 1);
                if (sum > k)
                    break;
            }
        sum <= k ? l = mid : r = mid;
    }

    printf("%lli", l);
    return 0;
}