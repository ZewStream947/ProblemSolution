#include <iostream>

using namespace std;

int n, x, y;

bool isGood(long long t)
{
    return t / x + (t - x) / y >= n;
}

int main()
{
    scanf("%d %d %d", &n, &x, &y);

    if (x > y)
        swap(x, y);

    long long mid, l = x, r = l * n;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        isGood(mid) ? r = mid : l = mid;
    }

    printf("%d", r);
    return 0;
}