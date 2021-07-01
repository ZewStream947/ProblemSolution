#include <cstdio>

int n;
long long st[(int)2e5 + 1];

void modify(int l, int r, long long val)
{
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            st[l++] += val;
        if (!(r & 1))
            st[r--] += val;
    }
}

long long query(int idx)
{
    long long res = 0;
    for (idx += n; idx; idx >>= 1)
        res += st[idx];
    return res;
}

int main()
{
    int m;

    scanf("%d %d", &n, &m);

    int type, l, r;
    long long val;
    while (m--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d %lli", &l, &r, &val);
            modify(l, --r, val);
        }
        else
            scanf("%d", &l), printf("%lli\n", query(l));
    }

    return 0;
}