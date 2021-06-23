#include <cstdio>

#define min(a, b) (a < b ? a : b)

int n, m;

struct assistant
{
    int blk, t, z, y;
} * ass;

bool good(int T)
{
    int total = 0;
    for (int index = 0; index < n; ++index)
    {
        total += (T / ass[index].blk) * ass[index].z + min(ass[index].z, (T % ass[index].blk) / ass[index].t);
        if (total >= m)
            return 1;
    }
    return total >= m;
}

int main()
{
    scanf("%d %d", &m, &n);

    ass = new assistant[n];

    for (int index = 0; index < n; ++index)
    {
        scanf("%d %d %d", &ass[index].t, &ass[index].z, &ass[index].y);
        ass[index].blk = ass[index].t * ass[index].z + ass[index].y;
    }

    int l = -1, r = 1e9, mid;

    while (l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        good(mid) ? r = mid : l = mid;
    }

    printf("%d\n", r);
    for (int index = 0, prev, total = 0; index < n; ++index)
    {
        if (total >= m)
        {
            printf("%d ", 0);
            continue;
        }
        prev = total;
        total = min(m, total + r / ass[index].blk * ass[index].z + min(ass[index].z, (r % ass[index].blk) / ass[index].t));
        printf("%d ", total - prev);
    }
    return 0;
}