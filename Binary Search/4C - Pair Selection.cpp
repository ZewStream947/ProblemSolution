#include <bits/stdc++.h>

#define MAXN int(1e5) + 5

using namespace std;

const double lim = 1e-6;
int a[MAXN], b[MAXN];
double tmp[MAXN];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int index = 0; index < n; ++index)
        scanf("%d %d", &a[index], &b[index]);

    double mid, l = 0, r = 1e5, sum;

    while (r - l > lim)
    {
        mid = (l + r) / 2.0;
        for (int index = 0; index < n; ++index)
            tmp[index] = a[index] - mid * b[index];
        sum = 0;
        sort(tmp, tmp + n);
        for (int index = n - k; index < n; ++index)
            sum += tmp[index];
        sum >= 0 ? l = mid : r = mid;
    }

    printf("%lf", (l + r) / 2.0);

    return 0;
}
