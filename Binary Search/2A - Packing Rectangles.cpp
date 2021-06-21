#include <cstdio>
#include <cmath>

#define max(a, b) (a > b ? a : b)

long long search(long long l, long long r, int a, int b, int n)
{
    long long mid;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        (mid / (long long)a) >= (long long)n / round(mid / (long long)b) ? r = mid : l = mid;
    }

    return r;
}

int main()
{
    int a, b, n;

    scanf("%d %d %d", &a, &b, &n);

    printf("%lli", search(1, (long long)max(a, b) * n, a, b, n));
    return 0;
}