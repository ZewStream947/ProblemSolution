#include <cstdio>

int main()
{

    double c, mid, l = 0.0, r = 1e10 + 1;
    scanf("%lf", &c);

    for (int cnt = 100; cnt; --cnt)
    {
        mid = (l + r) / 2.0;
        mid *mid *mid *mid + mid >= c ? r = mid : l = mid;
    }

    printf("%lf", double(r * r));
    return 0;
}